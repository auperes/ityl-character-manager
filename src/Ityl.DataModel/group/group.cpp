#include "group.h"

namespace Ityl::DataModel
{
    const QString Group::RootPartName = "Members";
    const QString Group::RootSubgroup = "members";

    Group::Group()
    {

    }

    Group::Group(const QString& name, const QString& nation, const GroupType& type, const QString& description)
        : _name(name)
        , _nation(nation)
        , _type(type)
        , _description(description)
    {

    }
}
