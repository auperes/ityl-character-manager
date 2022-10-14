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
        GroupInfo(const std::string& name, const GroupType& type);
        GroupInfo(const std::string& name, const std::string& role, const std::string& subgroupName, const GroupType& type, bool isOld);

        std::string getName() const { return _name; }
        std::string getRole() const { return _role; }
        std::string getSubgroupName() const { return _subgroupName; }
        GroupType getType() const { return _type; }
        bool getIsOld() const { return _isOld; }

        void setName(const std::string& name) { _name = name; }
        void setRole(const std::string& role) { _role = role; }
        void setSubgroupName(const std::string& subgroupName) { _subgroupName = subgroupName; }
        void setType(const GroupType& type) { _type = type; }
        void setIsOld(bool isOld) { _isOld = isOld; }

    private:
        std::string _name;
        std::string _role;
        std::string _subgroupName;
        GroupType _type;
        bool _isOld;
    };
}

