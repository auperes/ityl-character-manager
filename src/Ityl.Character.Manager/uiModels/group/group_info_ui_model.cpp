#include "group_info_ui_model.h"

namespace Ityl::Ui::UiModels
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

    QString GroupInfoUiModel::styledGroupInfo() const
    {
        if (_groupInfo.getIsOld())
            return "<i>" + getRichTextGroup() + "</i>" + getRichTextType();

        return getRichTextGroup() + getRichTextType();
    }

    QString GroupInfoUiModel::getColor() const
    {
        return _groupInfo.getIsOld() ? "#555555" : "#000000";
    }

    QString GroupInfoUiModel::getRichTextSubGroup() const
    {
        if (_groupInfo.getSubgroupName().isEmpty())
            return "";

        return " (" + _groupInfo.getSubgroupName() + ")";
    }

    QString GroupInfoUiModel::getRichTextType() const
    {
        if (_groupInfo.getType() == DataModel::GroupType::Group)
            return "";

        return "<i><font color=\"#888888\" size=◘\"8\"> - " + DataModel::Converters::convertGroupType(_groupInfo.getType()) + "</font></i>";
    }

    QString GroupInfoUiModel::getRichTextGroup() const
    {
        return "<font color=\"" + getColor() + "\">" + _groupInfo.getName() + getRichTextSubGroup() + "</font>";
    }
}
