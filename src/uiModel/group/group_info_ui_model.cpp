#include "group_info_ui_model.h"

namespace Ityl::UiModel
{
    GroupInfoUiModel::GroupInfoUiModel(QObject *parent)
        : QObject(parent)
    {

    }

    GroupInfoUiModel::GroupInfoUiModel(const DataModel::GroupInfo& groupInfo, QObject* parent)
        : QObject(parent)
        , _groupInfo(groupInfo)
    {

    }
}
