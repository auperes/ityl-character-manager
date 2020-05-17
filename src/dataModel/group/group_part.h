#pragma once

#include <memory>

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

        void setPartName(const QString& partName) { _partName = partName; }
        void setSubgroupName(const QString& subgroupName) {_subgroupName = subgroupName; }
        void setDescription(const QString& description) { _description = description; }
        void setParentPart(const std::shared_ptr<GroupPart>& parentPart) { _parentPart = parentPart; }

    private:
        QString _partName;
        QString _subgroupName;
        QString _description;
        std::weak_ptr<GroupPart> _parentPart;
    };
}
