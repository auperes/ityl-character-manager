#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>
#include <QDir>

#include "characters_provider.h"
#include "dataModel/app_config.h"
#include "qml_types_factory.h"
#include "reader/character_reader.h"
#include "uiModel/characters_ui_collection.h"

int main(int argc, char *argv[])
{
    try {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication app(argc, argv);

        QmlTypesFactory::registerTypes();
        AppConfig appConfig;

        QString charactersFolderPath(appConfig.getCharactersFolderPath());
        CharactersProvider charactersProvider(charactersFolderPath);

        CharactersUiCollection charactersUiCollection(charactersProvider);

        QQmlApplicationEngine engine;

        engine.rootContext()->setContextProperty(QStringLiteral("nationsList"), charactersProvider.nations());
        engine.rootContext()->setContextProperty(QStringLiteral("groupsList"), charactersProvider.groups());
        engine.rootContext()->setContextProperty(QStringLiteral("ethniesList"), charactersProvider.ethnies());
        engine.rootContext()->setContextProperty(QStringLiteral("charactersList"), &charactersUiCollection);

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
