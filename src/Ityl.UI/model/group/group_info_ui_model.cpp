#include "group_info_ui_model.h"

namespace Ityl::UI
{
    GroupInfoUiModel::GroupInfoUiModel(QObject *parent)
        : QObject(parent)
    {
    }

    QString GroupInfoUiModel::styledGroupInfo() const
    {
        if (_isOld)
            return "<i>" + getRichTextGroup() + "</i>" + getRichTextType();

        return getRichTextGroup() + getRichTextType();
    }

    QString GroupInfoUiModel::getColor() const
    {
        return _isOld ? "#555555" : "#000000";
    }

    QString GroupInfoUiModel::getRichTextRole() const
    {
        if (_role.isEmpty())
            return "";

        return " (" + _role + ")";
    }

    QString GroupInfoUiModel::getRichTextType() const
    {
        if (_type == "Groupe")
            return "";

        return "<i><font color=\"#888888\" size=◘\"8\"> - " + _type + "</font></i>";
    }

    QString GroupInfoUiModel::getRichTextGroup() const
    {
        return "<font color=\"" + getColor() + "\">" + _name + getRichTextRole() + "</font>";
    }
}
