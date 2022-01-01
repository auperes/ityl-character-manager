#include <iostream>

#include <QFont>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>
#include <QDir>
#include <QObject>

#include <config/app_config.h>
#include <providers/characters_provider.h>
#include <reader/home_view_reader.h>
#include <reader/json_reader_helpers.h>
#include <reader/settings_reader.h>
#include <uiModels/character/characters_ui_collection.h>
#include <uiModels/character/characters_ui_manager.h>
#include <uiModels/group/groups_ui_manager.h>
#include <uiModels/homeView/home_view_ui_model.h>
#include <uiModels/settings_ui_manager.h>

#include "qml_types_factory.h"
#include "q_custom_gui_application.h"

int main(int argc, char *argv[])
{
    try
    {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QCustomGuiApplication app(argc, argv);
        QFont font;
        font.setPointSize(10);
        app.setFont(font);
        app.setApplicationName("Ityl Character Manager");
        app.setOrganizationName("auperes");
        app.setOrganizationDomain("");

        Ityl::QmlTypesFactory::registerTypes();

        QString appConfigFilepath("settings/app_config.json");
        Ityl::Reader::SettingsReader::readSettingsFromFile(appConfigFilepath);
        QString charactersFolderPath = Ityl::DataModel::AppConfig::getCharactersFolderPath();
        QString groupsFolderPath = Ityl::DataModel::AppConfig::getGroupsFolderPath();
        auto nationsColor = Ityl::Reader::JsonReaderHelpers::readNationsColor(Ityl::DataModel::AppConfig::getColorsFilePath());

        Ityl::Ui::UiModels::CharactersUiManager charatersUiManager(charactersFolderPath, nationsColor);
        Ityl::Ui::UiModels::HomeViewUIModel homeViewUi(Ityl::Reader::HomeViewReader::readHomeViewFromFile(Ityl::DataModel::AppConfig::getHomeViewFilePath()));
        Ityl::Ui::UiModels::SettingsUiManager settingsUiManager;
        Ityl::Ui::UiModels::GroupsUiManager groupUiManager(groupsFolderPath, nationsColor, &charatersUiManager);

        QObject::connect(&settingsUiManager, SIGNAL(nationColorsChanged(const QMap<QString, QString>&)), &charatersUiManager, SLOT(changeNationColors(const QMap<QString, QString>&)));
        QObject::connect(&settingsUiManager, SIGNAL(nationColorsChanged(const QMap<QString, QString>&)), &groupUiManager, SLOT(changeNationColors(const QMap<QString, QString>&)));
        QObject::connect(&settingsUiManager, SIGNAL(charactersFolderPathChanged(const QString&)), &charatersUiManager, SLOT(changeCharactersLocation(const QString&)));
        QObject::connect(&settingsUiManager, SIGNAL(groupsFolderPathChanged(const QString&)), &groupUiManager, SLOT(changeGroupsLocation(const QString&)));
        QObject::connect(&settingsUiManager, SIGNAL(homeViewChanged(const DataModel::HomeView&)), &homeViewUi, SLOT(resetHomeView(const DataModel::HomeView&)));

        QQmlApplicationEngine engine;
       engine.addImportPath("./plugins");

        auto paths = engine.importPathList();

        engine.rootContext()->setContextProperty(QStringLiteral("charactersManager"), &charatersUiManager);
        engine.rootContext()->setContextProperty(QStringLiteral("groupsManager"), &groupUiManager);
        engine.rootContext()->setContextProperty(QStringLiteral("homeView"), &homeViewUi);
        engine.rootContext()->setContextProperty(QStringLiteral("settingsManager"), &settingsUiManager);

        engine.load(QUrl(QLatin1String("qrc:/ui/main.qml")));
        if (engine.rootObjects().isEmpty())
            return -1;

        return app.exec();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
