#pragma once

#include <string>

#include "group_type.h"

namespace Ityl::Core
{
    class GroupInfo
    {
    public:
        GroupInfo();
        GroupInfo(const std::string& name);

        std::string getName() const { return _name; }
        std::string getRole() const { return _role; }
        std::string getSubgroupName() const { return _subgroupName; }
        GroupType getType() const { return _type; }
        bool getIsOld() const { return _isOld; }

        GroupInfo& setName(const std::string& name);
        GroupInfo& setRole(const std::string& role);
        GroupInfo& setSubgroupName(const std::string& subgroupName);
        GroupInfo& setType(const GroupType& type);
        GroupInfo& setIsOld(bool isOld);

    private:
        std::string _name;
        std::string _role;
        std::string _subgroupName;
        GroupType _type;
        bool _isOld = false;
    };
}

