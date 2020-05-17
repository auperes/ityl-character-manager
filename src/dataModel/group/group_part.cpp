#include "group_part.h"

namespace Ityl::DataModel
{
    GroupPart::GroupPart()
        : _nestedLevel(0)
    {

    }

    GroupPart::GroupPart(const QString& partName, const QString& subgroupName, unsigned nestedLevel)
        : _partName(partName)
        , _subgroupName(subgroupName)
        , _nestedLevel(nestedLevel)
    {

    }
}
