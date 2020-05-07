#include "groups_ui_manager.h"

namespace Ityl::UiModel
{

    GroupsUiManager::GroupsUiManager(const QString& groupsFolderPath, const QMap<QString, QString>& nationColors, QObject* parent)
        : QObject(parent)
        , _groupsProvider(Provider::GroupsProvider(groupsFolderPath))
        , _nationColors(nationColors)
    {
    }

    GroupUiModel* GroupsUiManager::addGroup(const QString& name)
    {
        auto group = _groupsProvider.getGroup(name);

        return nullptr;

    }

    void GroupsUiManager::removeGroup(unsigned id)
    {
        _groupUiModels.remove(id);
    }

    void GroupsUiManager::refreshGroups()
    {

    }

    void GroupsUiManager::changeGroupsLocation(const QString& folderPath)
    {

    }

    void GroupsUiManager::changeNationColors(const QMap<QString, QString>& nationColors)
    {

    }

}
