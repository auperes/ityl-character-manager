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
        static QVector<QString> readRoles(const QJsonArray& jsonRoles);
        static QMap<QString, QList<DataModel::Skill>> readSkills(const QJsonArray& jsonSkills);
        static void fillRelationships(const QJsonArray& jsonRelationships, DataModel::Character& character);
        static QVector<QString> readEthnies(const QJsonArray& jsonEthnies);
        static QVector<QString> readGroups(const QJsonArray& jsonGroups);
        static QVector<QString> readAvatars(const QJsonArray& jsonAvatars);
    };
}
