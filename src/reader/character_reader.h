#pragma once

#include <QString>
#include <QJsonArray>

#include "../dataModel/character.h"

class CharacterReader
{
public:
    CharacterReader() = delete;
    virtual ~CharacterReader() = delete;

    static Character readCharacterFromFile(const QString& filepath);

private:
    static void fillValues(const QJsonArray& jsonValues, Character& character);
    static void fillRoles(const QJsonArray& jsonRoles, Character& character);
    static void fillSkills(const QJsonArray& jsonSkills, Character& character);
    static void fillRelationships(const QJsonArray& jsonRelationships, Character& character);
    static void fillEthnies(const QJsonArray& jsonEthnies, Character& character);
    static void fillGroups(const QJsonArray& jsonGroups, Character& character);
};
