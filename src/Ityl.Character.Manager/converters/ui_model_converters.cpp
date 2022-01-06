#include "ui_model_converters.h"

#include <iostream>

namespace Ityl::Ui::Converters
{
    Models::FilteringType convertFilteringType(const QString &type)
    {
        if (type == "Tous")
            return Models::FilteringType::None;
        if (type == QString("group"))
            return Models::FilteringType::Group;
        if (type == QString("ethnie"))
            return Models::FilteringType::Ethnie;
        if (type == QString("nation"))
            return Models::FilteringType::Nation;

        std::string errorMessage("Cannot convert type. Unknown value: " + type.toStdString());
        std::cout << errorMessage << std::endl;
        throw std::logic_error(errorMessage.c_str());
    }
}
