#pragma once

#include <QAbstractItemModel>
#include <QList>
#include <QObject>

#include "../character/characters_ui_collection.h"
#include "../../dataModel/group/group_part.h"

namespace Ityl::UiModel
{
    class GroupPartUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString name READ name CONSTANT)
        Q_PROPERTY(QString subgroupName READ subgroupName CONSTANT)
        Q_PROPERTY(QString description READ description CONSTANT)
        Q_PROPERTY(CharactersUiCollection* currentCharacters READ currentCharacters CONSTANT)
        Q_PROPERTY(CharactersUiCollection* oldCharacters READ oldCharacters CONSTANT)
        Q_PROPERTY(QAbstractItemModel* parts READ parts CONSTANT)
        Q_PROPERTY(bool hasParts READ hasParts CONSTANT)

    public:
        explicit GroupPartUiModel(const DataModel::GroupPart& part, QObject *parent = nullptr);

        const QString& name() { return _part.getPartName(); }
        const QString& subgroupName() { return _part.getSubgroupName(); }
        const QString& description() { return _part.getDescription(); }
        CharactersUiCollection* currentCharacters() { return _currentCharacters.get(); }
        CharactersUiCollection* oldCharacters() { return _oldCharacters.get(); }
        QAbstractItemModel* parts() { return _parts.get(); }
        bool hasParts() { return _partUiModels.count() > 0; }

        QList<std::shared_ptr<GroupPartUiModel>> getPartUiModels() const { return _partUiModels; }

        void addPart(const DataModel::GroupPart& part);
        void setCurrentCharactersUiCollection(const std::shared_ptr<CharactersUiCollection>& collection) { _currentCharacters = collection; }
        void setOldCharactersUiCollection(const std::shared_ptr<CharactersUiCollection>& collection) { _oldCharacters = collection; }

    signals:

    private:
        const DataModel::GroupPart& _part;

        std::shared_ptr<CharactersUiCollection> _currentCharacters;
        std::shared_ptr<CharactersUiCollection> _oldCharacters;

        std::unique_ptr<QAbstractItemModel> _parts;
        QList<std::shared_ptr<GroupPartUiModel>> _partUiModels;
    };
}
