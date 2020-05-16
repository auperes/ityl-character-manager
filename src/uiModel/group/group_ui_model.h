#pragma once

#include <memory>

#include <QAbstractItemModel>
#include <QList>
#include <QObject>

#include "../../converters/converters.h"
#include "../../dataModel/group/group.h"
#include "../../dataModel/group/group_part.h"
#include "group_part_ui_model.h"

namespace Ityl::UiModel
{
    class GroupUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString name READ name CONSTANT)
        Q_PROPERTY(QString type READ type CONSTANT)
        Q_PROPERTY(QString nationColor READ nationColor CONSTANT)
        Q_PROPERTY(QString description READ description CONSTANT)
        Q_PROPERTY(QAbstractItemModel* parts READ parts CONSTANT)
        Q_PROPERTY(bool hasParts READ hasParts CONSTANT)

    public:
        GroupUiModel();
        GroupUiModel(const std::shared_ptr<DataModel::Group>& group, const QString& nationColor, QObject *parent = nullptr);

        const QString& name() { return _group->getName(); }
        const QString type() { return DataModel::Converters::Converters::convertGroupType(_group->getType()); }
        const QString& nationColor() { return _nationColor; }
        const QString& description() { return _group->getDescription(); }
        QAbstractItemModel* parts() { return _parts.get(); }
        bool hasParts() { return _partUiModels.count() > 0; }

        QList<std::shared_ptr<GroupPartUiModel>> getPartUiModels() const { return _partUiModels; }

    private:
        std::shared_ptr<DataModel::Group> _group;
        QString _nationColor;

        std::unique_ptr<QAbstractItemModel> _parts;
        QList<std::shared_ptr<GroupPartUiModel>> _partUiModels;

        void addPart(const DataModel::GroupPart& part);
    };
}
