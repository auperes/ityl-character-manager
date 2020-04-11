#pragma once

#include <QString>
#include <QJsonArray>

#include "../dataModel/character/character.h"

class CharacterReader
{
public:
    CharacterReader() = delete;
    ~CharacterReader() = delete;

    static Character readCharacterFromFile(const QString& filepath);

private:
    static void fillValues(const QJsonArray& jsonValues, Character& character);
    static void fillRoles(const QJsonArray& jsonRoles, Character& character);
    static void fillSkills(const QJsonArray& jsonSkills, Character& character);
    static void fillRelationships(const QJsonArray& jsonRelationships, Character& character);
    static void fillEthnies(const QJsonArray& jsonEthnies, Character& character);
    static void fillGroups(const QJsonArray& jsonGroups, Character& character);
    static void fillAvatars(const QJsonArray& jsonAvatars, Character& character);
};
