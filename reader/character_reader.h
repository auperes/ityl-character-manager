#pragma once

#include <QString>
#include <QJsonArray>

#include "../dataModel/character/character.h"

namespace Ityl::Reader
{
    class CharacterReader
    {
    public:
        CharacterReader() = delete;
        ~CharacterReader() = delete;

        static DataModel::Character readCharacterFromFile(const QString& filepath);

    private:
        static void fillValues(const QJsonArray& jsonValues, DataModel::Character& character);
        static void fillRoles(const QJsonArray& jsonRoles, DataModel::Character& character);
        static void fillSkills(const QJsonArray& jsonSkills, DataModel::Character& character);
        static void fillRelationships(const QJsonArray& jsonRelationships, DataModel::Character& character);
        static void fillEthnies(const QJsonArray& jsonEthnies, DataModel::Character& character);
        static void fillGroups(const QJsonArray& jsonGroups, DataModel::Character& character);
        static void fillAvatars(const QJsonArray& jsonAvatars, DataModel::Character& character);
    };
}
