#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>
#include <QDir>

#include "characters_manager.h"
#include "model/character_model.h"
#include "model/qObjectWrapper/characters_wrapper.h"
#include "model/qObjectWrapper/skills_wrapper.h"
#include "model/qObjectWrapper/relationships_wrapper.h"
#include "model/skill_model.h"
#include "model/relationship_model.h"
#include "qml_types_factory.h"
#include "reader/character_reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QmlTypesFactory::registerTypes();

    QString charactersFolderPath("C:\\Users\\chach\\Dropbox\\Ecriture\\zzz_Les Royaumes d'Ityl\\Personnages - Groupes - Familles\\characters_json\\");
    CharactersManager charactersManager(charactersFolderPath);

    CharactersWrapper charactersWrapper;
    foreach(const Character& character, charactersManager.characters()) {
        charactersWrapper.appendCharacter(character);
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("charactersList"), &charactersWrapper);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
