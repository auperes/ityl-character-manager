#include "group_part.h"

namespace Ityl::DataModel
{
    GroupPart::GroupPart()
    {

    }

    GroupPart::GroupPart(const QString& partName, const QString& subgroupName)
        : _partName(partName)
        , _subgroupName(subgroupName)
    {

    }
}
