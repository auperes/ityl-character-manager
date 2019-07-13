#pragma once

#include <QObject>
#include <QVector>

#include "../../dataModel/character.h"

class CharactersWrapper : public QObject
{
    Q_OBJECT
public:
    explicit CharactersWrapper(QObject *parent = nullptr);

    QVector<Character> characters() const { return _characters; }
    void appendCharacter(const Character& character);

signals:

public slots:

private:
    QVector<Character> _characters;
};
