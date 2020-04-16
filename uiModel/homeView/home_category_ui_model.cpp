#include "home_category_ui_model.h"

namespace Ityl::UiModel
{
    HomeCategoryUiModel::HomeCategoryUiModel(QObject *parent)
        : QObject(parent)
    {

    }

    HomeCategoryUiModel::HomeCategoryUiModel(const QMap<DataModel::HomeElementType, QList<QString> > &elements, QObject *parent)
        : QObject(parent)
    {
        if (elements.contains(DataModel::HomeElementType::Region))
            _regions = elements[DataModel::HomeElementType::Region];

        if (elements.contains(DataModel::HomeElementType::Group))
            _groups = elements[DataModel::HomeElementType::Group];

        if (elements.contains(DataModel::HomeElementType::Guild))
            _guilds = elements[DataModel::HomeElementType::Guild];

        if (elements.contains(DataModel::HomeElementType::Family))
            _families = elements[DataModel::HomeElementType::Family];

        if (elements.contains(DataModel::HomeElementType::Background))
            _backgrounds = elements[DataModel::HomeElementType::Background];

        if (elements.contains(DataModel::HomeElementType::Organization))
            _organizations = elements[DataModel::HomeElementType::Organization];
    }
}
