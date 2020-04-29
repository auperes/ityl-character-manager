#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include "character_ui_model.h"
#include "filtering_type.h"

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
                FilteringType filteringType,
                QString filteringName,
                QObject *parent = nullptr);

        QAbstractItemModel* model() const { return _model.get(); }

        unsigned id() const { return _id; }
        FilteringType filteringType() const { return _filteringType; }
        QString filteringName() const { return _filteringName; }

        void setCharacters(QList<std::shared_ptr<CharacterUiModel>>&& characterUiModels);
        void addCharacter(const std::shared_ptr<CharacterUiModel> &characterUiModel);
        void clearCharacters();
        void addCharacters(const QList<std::shared_ptr<CharacterUiModel>>& characterUiModels);

    private:
        unsigned _id;
        std::unique_ptr<QAbstractItemModel> _model;
        QList<std::shared_ptr<CharacterUiModel>> _characterUiModels;
        FilteringType _filteringType;
        QString _filteringName;
    };
}
