#pragma once

#include <QString>

#include "filtering_type.h"

namespace Ityl::Ui::Models
{
    struct FilteringData
    {
    public:
        FilteringData() {}

        FilteringData(FilteringType type, const QString& name, const QString& subname)
            : _type(type)
            , _name(name)
            , _subname(subname)
        {}

        FilteringType _type;
        QString _name;
        QString _subname;
    };
}
