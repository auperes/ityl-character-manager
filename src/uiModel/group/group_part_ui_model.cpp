#include "group_part_ui_model.h"

namespace Ityl::UiModel
{
    GroupPartUiModel::GroupPartUiModel(const DataModel::GroupPart& part, QObject *parent)
        : QObject(parent)
        , _part(part)
    {

    }
}
