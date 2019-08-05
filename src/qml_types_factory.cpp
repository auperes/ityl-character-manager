#include "qml_types_factory.h"

#include <QQmlApplicationEngine>
#include <QMetaType>

#include "model/character_model.h"
#include "model/qObjectWrapper/characters_wrapper.h"
#include "model/qObjectWrapper/skills_wrapper.h"
#include "model/qObjectWrapper/relationships_wrapper.h"
#include "model/skill_model.h"
#include "model/relationship_model.h"
#include "reader/character_reader.h"
#include "uiModel/character_ui_model.h"
#include "uiModel/characters_ui_collection.h"

void QmlTypesFactory::registerTypes()
{
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


    qmlRegisterType<CharactersUiCollection>("Character", 1, 0, "CharactersUiCollection");
    qmlRegisterUncreatableType<CharacterUiModel>("Character", 1, 0, "CharacterUiModel",
        QStringLiteral("CharacterUiModel should not be created in QML"));
}
