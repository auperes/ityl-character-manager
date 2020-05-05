#include <iostream>

#include <QFont>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>
#include <QDir>
#include <QObject>

#include "characters_provider.h"
#include "dataModel/app_config.h"
#include "qml_types_factory.h"
#include "reader/home_view_reader.h"
#include "reader/json_reader_helpers.h"
#include "reader/settings_reader.h"
#include "uiModel/character/characters_ui_collection.h"
#include "uiModel/character/characters_ui_manager.h"
#include "uiModel/homeView/home_view_ui_model.h"
#include "uiModel/settings_ui_manager.h"

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
        QString charactersFolderPath(Ityl::DataModel::AppConfig::getCharactersFolderPath());
        Ityl::CharactersProvider charactersProvider(charactersFolderPath);

        Ityl::UiModel::CharactersUiManager charatersUiManager(&charactersProvider, std::move(Ityl::Reader::JsonReaderHelpers::readNationsColor(Ityl::DataModel::AppConfig::getColorsFilePath())));
        Ityl::UiModel::HomeViewUIModel homeViewUi(Ityl::Reader::HomeViewReader::readHomeViewFromFile(Ityl::DataModel::AppConfig::getHomeViewFilePath()));
        Ityl::UiModel::SettingsUiManager settingsUiManager;

        QObject::connect(&settingsUiManager, SIGNAL(nationColorsChanged(QMap<QString, QString>)), &charatersUiManager, SLOT(changeNationColors(QMap<QString, QString>)));
        QObject::connect(&settingsUiManager, SIGNAL(charactersFolderPathChanged(const QString&)), &charatersUiManager, SLOT(changeCharactersLocation(const QString&)));
        QObject::connect(&settingsUiManager, SIGNAL(homeViewChanged(const DataModel::HomeView&)), &homeViewUi, SLOT(resetHomeView(const DataModel::HomeView&)));

        QQmlApplicationEngine engine;

        engine.rootContext()->setContextProperty(QStringLiteral("charactersManager"), &charatersUiManager);
        engine.rootContext()->setContextProperty(QStringLiteral("homeView"), &homeViewUi);
        engine.rootContext()->setContextProperty(QStringLiteral("settingsManager"), &settingsUiManager);

        engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
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
