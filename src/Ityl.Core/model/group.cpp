#include "group.h"

namespace Ityl::Core
{
    const std::string Group::RootPartName = "Members";
    const std::string Group::RootSubgroup = "members";

    Group::Group(const std::string& name, const std::string& nation, const GroupType& type, const std::string& description)
        : _name(name)
        , _nation(nation)
        , _type(type)
        , _description(description)
    {

    }
}
