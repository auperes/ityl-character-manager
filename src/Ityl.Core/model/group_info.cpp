#include "group_info.h"

namespace Ityl::Core
{
    GroupInfo::GroupInfo()
        : GroupInfo("")
    {
    }

    GroupInfo::GroupInfo(const std::string& name)
        : GroupInfo(name, GroupType::Group)
    {
    }

    GroupInfo::GroupInfo(const std::string& name, const GroupType& type)
        : GroupInfo(name, "", "", type, false)
    {

    }

    GroupInfo::GroupInfo(const std::string& name, const std::string& role, const std::string& subgroupName, const GroupType& type, bool isOld)
        : _name(name)
        , _role(role)
        , _subgroupName(subgroupName)
        , _type(type)
        , _isOld(isOld)
    {
    }
}
