#include "group_part.h"

namespace Ityl::Core
{
    GroupPart::GroupPart()
        : _nestedLevel(0)
    {

    }

    GroupPart::GroupPart(const std::string& partName, const std::string& subgroupName, unsigned nestedLevel)
        : _partName(partName)
        , _subgroupName(subgroupName)
        , _nestedLevel(nestedLevel)
    {

    }
}
