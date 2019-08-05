#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include "../characters_provider.h"
#include "character_ui_model.h"

Q_DECLARE_METATYPE(CharacterUiModel)

class CharactersUiCollection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel* model READ model CONSTANT)
//    Q_DISABLE_COPY(CharactersUiCollection)

public:
    CharactersUiCollection();
    explicit CharactersUiCollection(const CharactersProvider &charactersProvider, QObject *parent = nullptr);

    QAbstractItemModel* model() const;

signals:

public slots:
    void filterCharacters(const QString& type, const QString& name);

private:
    std::unique_ptr<QAbstractItemModel> _model;
    const CharactersProvider &_charactersProvider;

    void addCharacter(const std::shared_ptr<Character> &character);
};

