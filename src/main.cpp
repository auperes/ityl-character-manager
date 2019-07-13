#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaType>

#include "model/character_model.h"
#include "model/qObjectWrapper/characters_wrapper.h"
#include "model/qObjectWrapper/skills_wrapper.h"
#include "model/qObjectWrapper/relationships_wrapper.h"
#include "model/skill_model.h"
#include "model/relationship_model.h"
#include "reader/character_reader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    CharactersWrapper charactersWrapper;
    charactersWrapper.appendCharacter(CharacterReader::readCharacterFromFile("C:\\Users\\chach\\Dropbox\\Ecriture\\zzz_Les Royaumes d'Ityl\\Personnages - Groupes - Familles\\characters_json\\analad_edethiel.json"));
    charactersWrapper.appendCharacter(CharacterReader::readCharacterFromFile("C:\\Users\\chach\\Dropbox\\Ecriture\\zzz_Les Royaumes d'Ityl\\Personnages - Groupes - Familles\\characters_json\\leanna_edethiel.json"));
    charactersWrapper.appendCharacter(CharacterReader::readCharacterFromFile("C:\\Users\\chach\\Dropbox\\Ecriture\\zzz_Les Royaumes d'Ityl\\Personnages - Groupes - Familles\\characters_json\\enewyr_edethiel.json"));

    qRegisterMetaType<std::shared_ptr<SkillsWrapper>>();
    qRegisterMetaType<std::shared_ptr<RelationshipsWrapper>>();
    qmlRegisterType<CharacterModel>("Character", 1, 0, "CharacterModel");
    qmlRegisterType<SkillModel>("Character", 1, 0, "SkillModel");
    qmlRegisterType<RelationshipModel>("Character", 1, 0, "RelationshipModel");

    qmlRegisterUncreatableType<CharactersWrapper>("Character", 1, 0, "CharactersWrapper",
        QStringLiteral("CharactersWrapper should not be created in QML"));
    qmlRegisterUncreatableType<SkillsWrapper>("Character", 1, 0, "SkillsWrapper",
        QStringLiteral("SkillsWrapper should not be created in QML"));
    qmlRegisterUncreatableType<RelationshipsWrapper>("Character", 1, 0, "RelationshipsWrapper",
        QStringLiteral("RelationshipsWrapper should not be created in QML"));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("charactersList"), &charactersWrapper);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
