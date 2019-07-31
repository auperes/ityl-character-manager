#pragma once

#include <QList>
#include <QString>

#include "dataModel/character.h"

class CharactersManager
{
public:
    CharactersManager(const QString &folderPath);

    QList<Character> characters() const;
    QList<QString> ethnies() const;
    QList<QString> groups() const;

    QList<Character> findCharacters(const std::function<bool (const Character&)> &predicate);

private:
    QList<Character> _characters;
    QList<QString> _ethnies;
    QList<QString> _groups;
};

