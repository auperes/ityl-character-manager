#include "character_reader.h"

#include <iostream>

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "../converters/converters.h"

Character CharacterReader::readCharacterFromFile(const QString& filepath)
{
    QString content;
    QFile file;
    file.setFileName(filepath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    content = file.readAll();
    file.close();
    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(content.toUtf8(), &error);
    if (document.isNull())
        throw std::logic_error(error.errorString().toStdString());

    QJsonObject jsonObject = document.object();

    Character character;
    QJsonObject characterObject = jsonObject.value("character").toObject();

    fillValues(characterObject["values"].toArray(), character);
    fillRoles(characterObject["roles"].toArray(), character);
    fillSkills(characterObject["skills"].toArray(), character);
    fillRelationships(characterObject["relationships"].toArray(), character);
    fillEthnies(characterObject["ethnies"].toArray(), character);
    fillGroups(characterObject["groups"].toArray(), character);
    fillAvatars(characterObject["avatars"].toArray(), character);

    return character;
}

void CharacterReader::fillValues(const QJsonArray& jsonValues, Character& character)
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
            character.setStatus(Converters::convertStatus(object["status"].toString()));
        else if (object.contains("description"))
            character.setDescription(object["description"].toString());
    }
}

void CharacterReader::fillRoles(const QJsonArray& jsonRoles, Character& character)
{
    QVector<QString> roles;
    roles.reserve(jsonRoles.size());
    for (auto value : jsonRoles)
    {
        QJsonObject object = value.toObject();
        roles.push_back(object["role"].toString());
    }
    character.setRoles(std::move(roles));
}

void CharacterReader::fillSkills(const QJsonArray& jsonSkills, Character& character)
{
    QMap<QString, QList<Skill>> skills;

    for (auto value : jsonSkills)
    {
        Skill skill;
        QJsonObject object = value.toObject();

        QString category = object["category"].toString();
        if (!skills.contains(category))
            skills.insert(category, QList<Skill>());

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
    character.setSkills(std::move(skills));
}

void CharacterReader::fillRelationships(const QJsonArray& jsonRelationships, Character& character)
{
    for (auto value : jsonRelationships)
    {
        QJsonObject object = value.toObject();
        Relationship relationship = Converters::convertRelationshipToEnum(object["link"].toString());
        QPair<QString, QString> linkedCharacter { object["firstName"].toString(), object["lastName"].toString() };

        character.addRelationship(relationship, linkedCharacter);
    }
}

void CharacterReader::fillEthnies(const QJsonArray& jsonEthnies, Character& character)
{
    QVector<QString> ethnies;
    ethnies.reserve(jsonEthnies.size());
    for (auto value : jsonEthnies)
    {
        QJsonObject object = value.toObject();
        ethnies.push_back(object["ethnie"].toString());
    }
    character.setEthnies(std::move(ethnies));
}

void CharacterReader::fillGroups(const QJsonArray& jsonGroups, Character& character)
{
    QVector<QString> groups;
    groups.reserve(jsonGroups.size());
    for (auto value : jsonGroups)
    {
        QJsonObject object = value.toObject();
        groups.push_back(object["group"].toString());
    }
    character.setGroups(std::move(groups));
}

void CharacterReader::fillAvatars(const QJsonArray &jsonAvatars, Character &character)
{
    QVector<QString> avatars;
    avatars.reserve(jsonAvatars.size());
    for (auto value : jsonAvatars)
    {
        QJsonObject object = value.toObject();
        avatars.push_back(object["avatar"].toString());
    }
    character.setAvatars(std::move(avatars));
}
