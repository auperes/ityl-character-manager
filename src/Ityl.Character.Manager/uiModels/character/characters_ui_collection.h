#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include "character_ui_model.h"
#include "../../models/character/filtering_data.h"

namespace Ityl::Ui::UiModels
{
    class CharactersUiCollection : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QAbstractItemModel* model READ model CONSTANT)

    public:
        CharactersUiCollection();
        explicit CharactersUiCollection(
                unsigned id,
                QList<std::shared_ptr<CharacterUiModel>>&& characterUiModels,
                Models::FilteringData filteringData,
                QObject *parent = nullptr);

        ~CharactersUiCollection() override = default;

        QAbstractItemModel* model() const { return _model.get(); }

        unsigned getId() const { return _id; }
        Models::FilteringData getFilteringData() const { return _filteringData; }
        const QList<std::shared_ptr<CharacterUiModel>>& getCharacterUiModels() const { return _characterUiModels; }

        void setCharacters(QList<std::shared_ptr<CharacterUiModel>>&& characterUiModels);
        void addCharacter(const std::shared_ptr<CharacterUiModel>& characterUiModel);
        void clearCharacters();
        void addCharacters(const QList<std::shared_ptr<CharacterUiModel>>& characterUiModels);

    private:
        unsigned _id;
        std::unique_ptr<QAbstractItemModel> _model;
        QList<std::shared_ptr<CharacterUiModel>> _characterUiModels;
        Models::FilteringData _filteringData;

        void addCharactersInternal(const QList<std::shared_ptr<CharacterUiModel>>& characterUiModels);
    };
}
