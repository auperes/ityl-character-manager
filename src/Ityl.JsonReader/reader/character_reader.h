#pragma once

#include <QString>
#include <QJsonArray>

#include <character/character.h>
#include <group/group_info.h>

namespace Ityl::Reader
{
    class CharacterReader
    {
    public:
        CharacterReader() = delete;
        ~CharacterReader() = delete;
        CharacterReader(const CharacterReader&) = delete;
        CharacterReader& operator=(const CharacterReader&) = delete;

        static DataModel::Character readCharacterFromFile(const QString& filepath);

    private:
        static void fillValues(const QJsonArray& jsonValues, DataModel::Character& character);
        static QVector<QString> readRoles(const QJsonArray& jsonRoles);
        static QMap<QString, QList<DataModel::Skill>> readSkills(const QJsonArray& jsonSkills);
        static void fillRelationships(const QJsonArray& jsonRelationships, DataModel::Character& character);
        static QVector<DataModel::GroupInfo> readEthnies(const QJsonArray& jsonEthnies);
        static QVector<DataModel::GroupInfo> readGroups(const QJsonArray& jsonGroups);
        static QVector<QString> readAvatars(const QJsonArray& jsonAvatars);
    };
}
