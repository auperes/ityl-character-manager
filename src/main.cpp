#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>
#include <QDir>

#include "characters_provider.h"
#include "model/character_model.h"
#include "model/qObjectWrapper/characters_wrapper.h"
#include "model/qObjectWrapper/skills_wrapper.h"
#include "model/qObjectWrapper/relationships_wrapper.h"
#include "model/skill_model.h"
#include "model/relationship_model.h"
#include "qml_types_factory.h"
#include "reader/character_reader.h"
#include "uiModel/characters_ui_collection.h"

int main(int argc, char *argv[])
{
    try {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        QGuiApplication app(argc, argv);

        QmlTypesFactory::registerTypes();

        QString charactersFolderPath("C:\\Users\\chach\\Dropbox\\Ecriture\\zzz_Les Royaumes d'Ityl\\Personnages - Groupes - Familles\\characters_json\\");
        CharactersProvider charactersProvider(charactersFolderPath);

        //    CharactersWrapper charactersWrapper(charactersManager);
        CharactersUiCollection charactersUiCollection(charactersProvider);

        QQmlApplicationEngine engine;

        //    engine.rootContext()->setContextProperty(QStringLiteral("charactersList"), &charactersWrapper);
        engine.rootContext()->setContextProperty(QStringLiteral("groupsList"), charactersProvider._groups);
        engine.rootContext()->setContextProperty(QStringLiteral("ethniesList"), charactersProvider._ethnies);
        engine.rootContext()->setContextProperty(QStringLiteral("charactersList"), &charactersUiCollection);

        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        if (engine.rootObjects().isEmpty())
            return -1;

        return app.exec();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
