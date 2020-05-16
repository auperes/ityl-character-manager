#pragma once

#include <QString>
#include <QVector>

namespace Ityl::DataModel
{
    class GroupPart
    {
    public:
        GroupPart();
        GroupPart(const QString& partName, const QString& subgroupName);

        const QString& getPartName() const { return _partName; }
        const QString& getSubgroupName() const { return _subgroupName; }
        const QString& getDescription() const { return _description; }
        const QVector<GroupPart>& getParts() const { return _parts; }

        void setPartName(const QString& partName) { _partName = partName; }
        void setSubgroupName(const QString& subgroupName) {_subgroupName = subgroupName; }
        void setDescription(const QString& description) { _description = description; }
        void setParts(const QVector<GroupPart>& parts) { _parts = parts; }

    private:
        QString _partName;
        QString _subgroupName;
        QString _description;

        QVector<GroupPart> _parts;
    };
}
