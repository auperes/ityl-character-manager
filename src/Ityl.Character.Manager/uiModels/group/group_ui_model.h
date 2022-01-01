#pragma once

#include <memory>

#include <QAbstractItemModel>
#include <QList>
#include <QMap>
#include <QObject>
#include <QString>

#include <converters/data_model_converters.h>
#include <group/group.h>
#include <group/group_part.h>

#include "group_part_ui_model.h"

namespace Ityl::Ui::UiModels
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
        const QString type() { return DataModel::Converters::convertGroupType(_group->getType()); }
        const QString& nationColor() { return _nationColor; }
        const QString& description() { return _group->getDescription(); }
        QAbstractItemModel* parts() { return _parts.get(); }
        bool hasParts() { return _partUiModelsBySubgroupName.count() > 0; }

        const QMap<QString, std::shared_ptr<GroupPartUiModel>>& getPartUiModelsBySubgroupName() const { return _partUiModelsBySubgroupName; }

    private:
        std::shared_ptr<DataModel::Group> _group;
        QString _nationColor;

        std::unique_ptr<QAbstractItemModel> _parts;
        QList<std::shared_ptr<GroupPartUiModel>> _partUiModels;
        QMap<QString, std::shared_ptr<GroupPartUiModel>> _partUiModelsBySubgroupName;

        void addPart(const DataModel::GroupPart& part);
    };
}
