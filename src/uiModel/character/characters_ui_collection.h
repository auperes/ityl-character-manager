#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include "character_ui_model.h"
#include "filtering_data.h"

namespace Ityl::UiModel
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
                FilteringData filteringData,
                QObject *parent = nullptr);

        QAbstractItemModel* model() const { return _model.get(); }

        unsigned getId() const { return _id; }
        FilteringData getFilteringData() const { return _filteringData; }

        void setCharacters(QList<std::shared_ptr<CharacterUiModel>>&& characterUiModels);
        void addCharacter(const std::shared_ptr<CharacterUiModel>& characterUiModel);
        void clearCharacters();
        void addCharacters(const QList<std::shared_ptr<CharacterUiModel>>& characterUiModels);

    private:
        unsigned _id;
        std::unique_ptr<QAbstractItemModel> _model;
        QList<std::shared_ptr<CharacterUiModel>> _characterUiModels;
        FilteringData _filteringData;
    };
}
