#pragma once

#include <memory>

#include <string>
#include <vector>

namespace Ityl::Core
{
    class GroupPart
    {
    public:
        GroupPart();
        GroupPart(const std::string& partName, const std::string& subgroupName, unsigned nestedLevel = 0);

        const std::string& getPartName() const { return _partName; }
        const std::string& getSubgroupName() const { return _subgroupName; }
        const std::string& getDescription() const { return _description; }
        unsigned getNestedLevel() const { return _nestedLevel; }

        void setPartName(const std::string& partName) { _partName = partName; }
        void setSubgroupName(const std::string& subgroupName) {_subgroupName = subgroupName; }
        void setDescription(const std::string& description) { _description = description; }
        void setParentPart(const std::shared_ptr<GroupPart>& parentPart) { _parentPart = parentPart; }
        void setNestedLevel(unsigned nestedLevel) { _nestedLevel = nestedLevel; }

    private:
        std::string _partName;
        std::string _subgroupName;
        std::string _description;
        std::weak_ptr<GroupPart> _parentPart;
        unsigned _nestedLevel;
    };
}
