#include <iostream>

#include <QFont>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>
#include <QDir>

#include "characters_provider.h"
#include "dataModel/app_config.h"
#include "qml_types_factory.h"
#include "reader/home_view_reader.h"
#include "uiModel/character/characters_ui_collection.h"
#include "uiModel/character/characters_ui_manager.h"
#include "uiModel/homeView/home_view_ui_model.h"

int main(int argc, char *argv[])
{
    try {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication app(argc, argv);
        QFont font;
        font.setPointSize(10);
        app.setFont(font);

        Ityl::QmlTypesFactory::registerTypes();
        Ityl::DataModel::AppConfig appConfig;

        QString charactersFolderPath(appConfig.getCharactersFolderPath());
        Ityl::CharactersProvider charactersProvider(charactersFolderPath);

        Ityl::UiModel::CharactersUiManager charatersUiManager(&charactersProvider);
        Ityl::UiModel::HomeViewUIModel homeViewUi(Ityl::Reader::HomeViewReader::readHomeViewFromFile(appConfig.getHomeViewFilePath()));

        QQmlApplicationEngine engine;

        engine.rootContext()->setContextProperty(QStringLiteral("charactersManager"), &charatersUiManager);
        engine.rootContext()->setContextProperty(QStringLiteral("homeView"), &homeViewUi);

        engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
        if (engine.rootObjects().isEmpty())
            return -1;

        return app.exec();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
