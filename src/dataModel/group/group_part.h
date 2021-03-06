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
        GroupPart(const QString& partName, const QString& subgroupName, unsigned nestedLevel = 0);

        const QString& getPartName() const { return _partName; }
        const QString& getSubgroupName() const { return _subgroupName; }
        const QString& getDescription() const { return _description; }
        unsigned getNestedLevel() const { return _nestedLevel; }

        void setPartName(const QString& partName) { _partName = partName; }
        void setSubgroupName(const QString& subgroupName) {_subgroupName = subgroupName; }
        void setDescription(const QString& description) { _description = description; }
        void setParentPart(const std::shared_ptr<GroupPart>& parentPart) { _parentPart = parentPart; }
        void setNestedLevel(unsigned nestedLevel) { _nestedLevel = nestedLevel; }

    private:
        QString _partName;
        QString _subgroupName;
        QString _description;
        std::weak_ptr<GroupPart> _parentPart;
        unsigned _nestedLevel;
    };
}
