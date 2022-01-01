#pragma once

#include <memory>

#include <QDir>
#include <QMap>
#include <QString>

#include <group/group.h>

namespace Ityl::Business::Providers
{
    class GroupsProvider
    {
    public:
        GroupsProvider(const QString& folderPath);

        std::shared_ptr<DataModel::Group> getGroup(const QString& name);

        void setFolderPath(const QString& folderPath) { _folder = QDir(folderPath); }

        void refreshGroups();

    private:
        QDir _folder;
        QMap<QString, std::shared_ptr<DataModel::Group>> _groupsByName;

        void loadGroups();
    };
}
