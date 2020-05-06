#pragma once

#include <QString>
#include <QVector>

namespace Ityl::DataModel
{
    class GroupPart
    {
    public:
        GroupPart();

        const QString& getPartName() const { return _partName; }
        const QString& getSubGroupName() const { return _subGroupName; }
        const QString& getDescription() const { return _description; }
        const QVector<GroupPart>& getParts() const { return _parts; }

        void setPartName(const QString& partName) { _partName = partName; }
        void setSubGroupName(const QString& subGroupName) {_subGroupName = subGroupName; }
        void setDescription(const QString& description) { _description = description; }
        void setParts(const QVector<GroupPart>& parts) { _parts = parts; }

    private:
        QString _partName;
        QString _subGroupName;
        QString _description;

        QVector<GroupPart> _parts;
    };
}
