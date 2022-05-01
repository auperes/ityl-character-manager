#include "group_info.h"

namespace Ityl::DataModel
{
    GroupInfo::GroupInfo()
        : GroupInfo("")
    {
    }

    GroupInfo::GroupInfo(const QString& name)
        : GroupInfo(name, GroupType::Group)
    {
    }

    GroupInfo::GroupInfo(const QString& name, const GroupType& type)
        : GroupInfo(name, "", "", type, false)
    {

    }

    GroupInfo::GroupInfo(const QString& name, const QString& role, const QString& subgroupName, const GroupType& type, bool isOld)
        : _name(name)
        , _role(role)
        , _subgroupName(subgroupName)
        , _type(type)
        , _isOld(isOld)
    {
    }
}
