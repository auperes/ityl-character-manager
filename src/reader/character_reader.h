#pragma once

#include <QObject>
#include <QString>
#include <QJsonArray>

#include "../dataModel/character.h"

class CharacterReader : public QObject
{
    Q_OBJECT

public:
    CharacterReader() = delete;
    virtual ~CharacterReader();

    static Character readCharacterFromFile(const QString& filepath);

public slots:
    static void readCharacterMock();

private:
    static void fillValues(const QJsonArray& jsonValues, Character& character);
    static void fillRoles(const QJsonArray& jsonRoles, Character& character);
    static void fillSkills(const QJsonArray& jsonSkills, Character& character);
    static void fillRelationships(const QJsonArray& jsonRelationships, Character& character);
    static void fillEthnies(const QJsonArray& jsonEthnies, Character& character);
    static void fillGroups(const QJsonArray& jsonGroups, Character& character);
};
