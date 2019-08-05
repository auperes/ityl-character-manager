#pragma once

#include <QList>
#include <QString>

#include "dataModel/character.h"

class CharactersProvider
{
public:
    CharactersProvider(const QString &folderPath);

    QStringList _ethnies;
    QStringList _groups;

    QList<std::shared_ptr<Character>> characters() const;
    QList<QString> ethnies() const;
    QList<QString> groups() const;

    QList<std::shared_ptr<Character>> findCharacters(const std::function<bool (const std::shared_ptr<Character>&)> &predicate) const;

private:
    QList<std::shared_ptr<Character>> _characters;
};

