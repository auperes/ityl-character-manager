#pragma once

#include <QAbstractListModel>

#include "group/group_ui_model.h"
#include "group/groups_ui_manager.h"

namespace Ityl::Ui::UiModels
{
    class TabContentUiCollection : public QAbstractListModel
    {
        Q_OBJECT

    public:
        Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        Q_INVOKABLE void addGroup(const QString& name);
        Q_INVOKABLE void removeGroup(int row);

        TabContentUiCollection(GroupsUiManager* groupsUiManager);

        ~TabContentUiCollection() override = default;

    private:
        QList<std::shared_ptr<GroupUiModel>> _groupUiModels;

        GroupsUiManager* _groupsUiManager;
    };
}
