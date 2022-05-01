#include "character_reader.h"

#include <QFile>
#include <QString>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <converters/data_model_converters.h>
#include <reader/json_reader_helpers.h>

namespace Ityl::Reader
{
    DataModel::Character CharacterReader::readCharacterFromFile(const QString& filepath)
    {
        QJsonObject jsonObject = JsonReaderHelpers::readJsonFile(filepath);

        DataModel::Character character;
        QJsonObject characterObject = jsonObject.value("character").toObject();

        fillValues(characterObject["values"].toArray(), character);
        character.setRoles(readRoles(characterObject["roles"].toArray()));
        character.setSkills(readSkills(characterObject["skills"].toArray()));
        fillRelationships(characterObject["relationships"].toArray(), character);
        character.setEthnies(readEthnies(characterObject["ethnies"].toArray()));
        character.setGroups(readGroups(characterObject["groups"].toArray()));
        fillAvatars(characterObject["avatars"].toArray(), character);

        return character;
    }

    void CharacterReader::fillValues(const QJsonArray& jsonValues, DataModel::Character& character)
    {
        for (auto value : jsonValues)
        {
            QJsonObject object = value.toObject();
            if (object.contains("firstName"))
                character.setFirstName(object["firstName"].toString());
            else if (object.contains("lastName"))
                character.setLastName(object["lastName"].toString());
            else if (object.contains("birthName"))
                character.setBirthName(object["birthName"].toString());
            else if (object.contains("nickName"))
                character.setNickName(object["nickName"].toString());
            else if (object.contains("title"))
                character.setTitle(object["title"].toString());
            else if (object.contains("quote"))
                character.setQuote(object["quote"].toString());
            else if (object.contains("birthPlace"))
                character.setBirthPlace(object["birthPlace"].toString());
            else if (object.contains("livelyPlace"))
                character.setLivelyPlace(object["livelyPlace"].toString());
            else if (object.contains("birthNation"))
                character.setBirthNation(object["birthNation"].toString());
            else if (object.contains("currentNation"))
                character.setCurrentNation(object["currentNation"].toString());
            else if (object.contains("status"))
                character.setStatus(DataModel::Converters::convertStatus(object["status"].toString()));
            else if (object.contains("description"))
                character.setDescription(object["description"].toString());
        }
    }

    QVector<QString> CharacterReader::readRoles(const QJsonArray& jsonRoles)
    {
        QVector<QString> roles;
        roles.reserve(jsonRoles.size());
        for (auto value : jsonRoles)
        {
            QJsonObject object = value.toObject();
            roles.push_back(object["role"].toString());
        }

        return roles;
    }

    QMap<QString, QList<DataModel::Skill>> CharacterReader::readSkills(const QJsonArray& jsonSkills)
    {
        QMap<QString, QList<DataModel::Skill>> skills;

        for (auto value : jsonSkills)
        {
            DataModel::Skill skill;
            QJsonObject object = value.toObject();

            QString category = object["category"].toString();
            if (!skills.contains(category))
                skills.insert(category, QList<DataModel::Skill>());

            skill.setType(object["name"].toString());

            if (object.contains("specialties"))
            {
                QVector<QString> specialties;
                QJsonArray specialtiesJson = object["specialties"].toArray();
                specialties.reserve(specialtiesJson.size());

                for (auto specialty : specialtiesJson)
                {
                    QJsonObject specialtyObject = specialty.toObject();
                    specialties.push_back(specialtyObject["specialty"].toString());
                }
                skill.setSpecialties(specialties);
            }
            skills[category].push_back(skill);
        }

        return skills;
    }

    void CharacterReader::fillRelationships(const QJsonArray& jsonRelationships, DataModel::Character& character)
    {
        for (auto value : jsonRelationships)
        {
            QJsonObject object = value.toObject();
            DataModel::Relationship relationship = DataModel::Converters::convertRelationshipToEnum(object["link"].toString());
            QPair<QString, QString> linkedCharacter { object["firstName"].toString(), object["lastName"].toString() };

            character.addRelationship(relationship, linkedCharacter);
        }
    }

    QVector<DataModel::GroupInfo> CharacterReader::readEthnies(const QJsonArray& jsonEthnies)
    {
        QVector<DataModel::GroupInfo> ethnies;
        ethnies.reserve(jsonEthnies.size());
        for (auto value : jsonEthnies)
        {
            QJsonObject object = value.toObject();
            ethnies.push_back(DataModel::GroupInfo(object["ethnie"].toString(), DataModel::GroupType::Ethnie));
        }

        return ethnies;
    }

    QVector<DataModel::GroupInfo> CharacterReader::readGroups(const QJsonArray& jsonGroups)
    {
        QVector<DataModel::GroupInfo> groups;
        groups.reserve(jsonGroups.size());
        for (auto value : jsonGroups)
        {
            QJsonObject object = value.toObject();
            DataModel::GroupInfo groupInfo(object["group"].toString());

            if (object.contains("subgroup"))
                groupInfo.setSubgroupName(object["subgroup"].toString());
            if (object.contains("role"))
                groupInfo.setRole(object["role"].toString());
            if (object.contains("type"))
                groupInfo.setType(DataModel::Converters::convertGroupType(object["type"].toString()));
            if (object.contains("old"))
                groupInfo.setIsOld(object["old"].toBool());

            groups.push_back(groupInfo);
        }

        return groups;
    }

    void CharacterReader::fillAvatars(const QJsonArray &jsonAvatars, DataModel::Character& character)
    {
        QVector<QString> avatars;
        avatars.reserve(jsonAvatars.size());
        for (auto value : jsonAvatars)
        {
            QJsonObject object = value.toObject();
            if (object.contains("isMiniAvatar") && object["isMiniAvatar"].toBool())
                character.setMiniAvatar(object["avatar"].toString());

            avatars.push_back(object["avatar"].toString());
        }

        character.setAvatars(avatars);
    }
}
