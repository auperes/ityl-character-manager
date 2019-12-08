#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include "../characters_provider.h"
#include "character_ui_model.h"

class CharactersUiCollection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel* model READ model CONSTANT)

public:
    CharactersUiCollection();
    explicit CharactersUiCollection(CharactersProvider *charactersProvider, QObject *parent = nullptr);

    QAbstractItemModel* model() const { return _model.get(); }

signals:
    void charactersChanged();

public slots:
    void filterCharacters(const QString& type, const QString& name);
    void refreshCharacters();

private:
    std::unique_ptr<QAbstractItemModel> _model;
    CharactersProvider *_charactersProvider;
    QList<std::shared_ptr<CharacterUiModel>> _characterUiModels;

    void addCharacter(const std::shared_ptr<Character> &character);
    void clearCharacters();
    void addCharacters(const QList<std::shared_ptr<Character>>& characters);
};
