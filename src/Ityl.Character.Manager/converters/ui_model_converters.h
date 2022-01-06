#pragma once

#include <QString>

#include "../models/character/filtering_type.h"

namespace Ityl::Ui::Converters
{
    Models::FilteringType convertFilteringType(const QString& type);
}
