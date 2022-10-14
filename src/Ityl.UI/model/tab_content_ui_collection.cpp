#include "tab_content_ui_collection.h"

#include <iostream>

#include <QQmlEngine>
#include <QStandardItemModel>

namespace Ityl::Ui::UiModels
{
    TabContentUiCollection::TabContentUiCollection(GroupsUiManager* groupsUiManager)
        : QAbstractListModel(nullptr)
        , _groupsUiManager(groupsUiManager)
    {
    }

    int TabContentUiCollection::rowCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return _groupUiModels.count();
    }

    QVariant TabContentUiCollection::data(const QModelIndex &index, int role) const
    {
        auto uiModel = _groupUiModels.at(index.row());
        return QVariant::fromValue(uiModel.get());
    }

    void TabContentUiCollection::addGroup(const QString& name)
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        auto model = _groupsUiManager->createGroup(name);
        QQmlEngine::setObjectOwnership(model.get(), QQmlEngine::CppOwnership);
        _groupUiModels.append(model);
        endInsertRows();
    }

    void TabContentUiCollection::removeGroup(int row)
    {
        if (row < 0 || row >= _groupUiModels.count())
                return;

        beginRemoveRows(QModelIndex(), rowCount(), rowCount());
        _groupUiModels.removeAt(row);
        endRemoveRows();
    }
}
