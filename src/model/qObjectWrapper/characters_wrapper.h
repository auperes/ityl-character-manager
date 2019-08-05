#pragma once

#include <QObject>
#include <QVector>

#include "../../characters_provider.h"
#include "../../dataModel/character.h"

class CharactersWrapper : public QObject
{
    Q_OBJECT
public:
    explicit CharactersWrapper(const CharactersProvider& charactersProvider, QObject *parent = nullptr);

    QVector<Character> characters() const { return _characters; }

signals:

public slots:

private:
    QVector<Character> _characters;
    CharactersProvider _charactersProvider;
};
