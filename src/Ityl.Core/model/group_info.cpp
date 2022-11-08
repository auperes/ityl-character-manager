#include "group_info.h"

namespace Ityl::Core
{
    GroupInfo::GroupInfo()
        : GroupInfo("")
    {
    }

    GroupInfo::GroupInfo(const std::string& name)
        : _name(name)
    {
    }

    GroupInfo &GroupInfo::setName(const std::string &name)
    {
      _name = name;
      return *this;
    }

    GroupInfo &GroupInfo::setRole(const std::string &role)
    {
      _role = role;
      return *this;
    }

    GroupInfo &GroupInfo::setSubgroupName(const std::string &subgroupName)
    {
      _subgroupName = subgroupName;
      return *this;
    }

    GroupInfo &GroupInfo::setType(const GroupType &type)
    {
      _type = type;
      return *this;
    }

    GroupInfo &GroupInfo::setIsOld(bool isOld)
    {
      _isOld = isOld;
      return *this;
    }
}
