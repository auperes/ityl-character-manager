#include "character_dto.h"

namespace Ityl::Json
{
    void CharacterDto::setValues(const QHash<QString, QString>& newValues)
    {
        _values = newValues;
    }

    void CharacterDto::setRoles(const QVector<QString>& newRoles)
    {
        _roles = newRoles;
    }

    void CharacterDto::setSkills(const QVector<SkillDto>& newSkills)
    {
        _skills = newSkills;
    }

    void CharacterDto::setRelationships(const QVector<RelationshipDto>& newRelationships)
    {
        _relationships = newRelationships;
    }

    void CharacterDto::setEthnies(const QVector<QString>& newEthnies)
    {
        _ethnies = newEthnies;
    }

    void CharacterDto::setGroups(const QVector<GroupDto>& newGroups)
    {
        _groups = newGroups;
    }

    void CharacterDto::setAvatars(const QVector<AvatarDto>& newAvatars)
    {
        _avatars = newAvatars;
    }

    void CharacterDto::read(const JsonModelMapper& mapper, const QJsonObject& json)
    {
        QJsonObject characterObject = json.value(mapper.get(JsonKey::Character)).toObject();
        readValues(characterObject[mapper.get(JsonKey::Values)].toArray());
        readRoles(mapper, characterObject[mapper.get(JsonKey::Roles)].toArray());
        readSkills(characterObject[mapper.get(JsonKey::Skills)].toArray());
        readRelationships(characterObject[mapper.get(JsonKey::Relationships)].toArray());
        readEthnies(mapper, characterObject[mapper.get(JsonKey::Ethnies)].toArray());
        readGroups(characterObject[mapper.get(JsonKey::Groups)].toArray());
        readAvatars(characterObject[mapper.get(JsonKey::Avatars)].toArray());
    }

    void CharacterDto::readValues(const QJsonArray& jsonValues)
    {
        for (auto value : jsonValues)
        {
            QJsonObject object = value.toObject();
            _values.emplace(object.begin().key(), object.begin().value().toString());
        }
    }

    void CharacterDto::readRoles(const JsonModelMapper& mapper, const QJsonArray& jsonRoles)
    {
        _roles.reserve(jsonRoles.size());
        for (auto value : jsonRoles)
        {
            QJsonObject object = value.toObject();
            _roles.push_back(object[mapper.get(JsonKey::Role)].toString());
        }
    }

    void CharacterDto::readSkills(const QJsonArray& jsonSkills)
    {
        _skills.reserve(jsonSkills.size());
        for (auto value : jsonSkills)
        {
            SkillDto skill;
            skill.read(value.toObject());
            _skills.push_back(skill);
        }
    }

    void CharacterDto::readRelationships(const QJsonArray& jsonRelationships)
    {
        _relationships.reserve(jsonRelationships.size());
        for (auto value : jsonRelationships)
        {
            RelationshipDto relationship;
            relationship.read(value.toObject());
            _relationships.push_back(relationship);
        }
    }

    void CharacterDto::readEthnies(const JsonModelMapper& mapper, const QJsonArray& jsonEthnies)
    {
        _ethnies.reserve(jsonEthnies.size());
        for (auto value : jsonEthnies)
        {
            QJsonObject object = value.toObject();
            _ethnies.push_back(object[mapper.get(JsonKey::Ethnie)].toString());
        }
    }

    void CharacterDto::readGroups(const QJsonArray& jsonGroups)
    {
        _groups.reserve(jsonGroups.size());
        for (auto value : jsonGroups)
        {
            GroupDto group;
            group.read(value.toObject());
            _groups.push_back(group);
        }
    }

    void CharacterDto::readAvatars(const QJsonArray& jsonAvatars)
    {
        _avatars.reserve(jsonAvatars.size());
        for (auto value : jsonAvatars)
        {
            AvatarDto avatar;
            avatar.read(value.toObject());
            _avatars.push_back(avatar);
        }
    }

    void CharacterDto::write(QJsonObject& json)
    {

    }
}
