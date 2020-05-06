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
        Q_PROPERTY(QString description READ description CONSTANT)
        Q_PROPERTY(CharactersUiCollection* characters READ characters CONSTANT)
        Q_PROPERTY(QAbstractItemModel* parts READ parts CONSTANT)

    public:
        explicit GroupPartUiModel(const DataModel::GroupPart& part, QObject *parent = nullptr);

        const QString& name() { return _part.getPartName(); }
        const QString& description() { return _part.getDescription(); }
        CharactersUiCollection* characters() { return _characters.get(); }
        QAbstractItemModel* parts() { return _parts.get(); }

    signals:

    private:
        const DataModel::GroupPart& _part;

        std::shared_ptr<CharactersUiCollection> _characters;

        std::unique_ptr<QAbstractItemModel> _parts;
        QList<std::shared_ptr<GroupPartUiModel>> _partUiModels;
    };
}
