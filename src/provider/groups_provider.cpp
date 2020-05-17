#include "groups_provider.h"

#include <iostream>

#include "../reader/group_reader.h"

namespace Ityl::Provider
{
    GroupsProvider::GroupsProvider(const QString& folderPath)
        : _folder(QDir(folderPath))
    {
        loadGroups();
    }

    void GroupsProvider::loadGroups()
    {
        QStringList files = _folder.entryList(QStringList() << "*.json", QDir::Files);

        for (const QString& filename : files)
        {
            try
            {
                auto group = std::make_shared<DataModel::Group>(Reader::GroupReader::readGroupFromFile(_folder.filePath(filename)));
                group->addPart(std::make_shared<DataModel::GroupPart>(DataModel::Group::RootPart, DataModel::Group::RootSubgroup));
                _groupsByName.insert(group->getName(), group);
            }
            catch (const std::logic_error& ex)
            {
                std::cout << "Warning: An error occured when reading group file " << filename.toStdString() << " (" << ex.what() << ")." << std::endl;
            }
        }
    }

    std::shared_ptr<DataModel::Group> GroupsProvider::getGroup(const QString& name)
    {
        if (_groupsByName.contains(name))
            return _groupsByName[name];

        return nullptr;
    }

    void GroupsProvider::refreshGroups()
    {
        _groupsByName.clear();
        loadGroups();
    }
}
