#include "groups_ui_manager.h"

#include <iostream>

#include <QQmlEngine>

namespace Ityl::UiModel
{

    GroupsUiManager::GroupsUiManager(const QString& groupsFolderPath, const QMap<QString, QString>& nationColors, CharactersUiManager* characterUiManager, QObject* parent)
        : QObject(parent)
        , _groupsProvider(Provider::GroupsProvider(groupsFolderPath))
        , _nationColors(nationColors)
        , _characterUiManager(characterUiManager)
    {
    }

    GroupUiModel* GroupsUiManager::addGroup(const QString& name)
    {
        auto group = _groupsProvider.getGroup(name);

        if (!group)
        {
            std::cout << "The group " << name.toStdString() << " has not been found." << std::endl;
            return nullptr;
        }

        auto collectionsBySubgroup = _characterUiManager->getCollectionsFromGroup(name);
        auto groupUiModel = std::make_shared<GroupUiModel>(group, getNationColor(group->getNation()));

        auto& partsBySubgroup = groupUiModel->getPartUiModelsBySubgroupName();

        for (const auto& subgroup : collectionsBySubgroup.keys())
        {
            if (partsBySubgroup.contains(subgroup))
            {
                auto& partUiModel = partsBySubgroup[subgroup];
                partUiModel->setCurrentCharactersUiCollection(collectionsBySubgroup[subgroup]._currentUiCharacters);
                partUiModel->setOldCharactersUiCollection(collectionsBySubgroup[subgroup]._oldUiCharacters);
            }
            else
                std::cout << "Missing subgroup " << subgroup.toStdString() << " in group " << name.toStdString() << std::endl;
        }

        _groupUiModels.insert(_idSequence++, groupUiModel);
        QQmlEngine::setObjectOwnership(groupUiModel.get(), QQmlEngine::CppOwnership);

        return groupUiModel.get();
    }

    void GroupsUiManager::removeGroup(unsigned id)
    {
        _groupUiModels.remove(id);
    }

    void GroupsUiManager::changeGroupsLocation(const QString& folderPath)
    {
        _groupsProvider.setFolderPath(folderPath);
        _groupsProvider.refreshGroups();
    }

    void GroupsUiManager::changeNationColors(const QMap<QString, QString>& nationColors)
    {
        _nationColors = nationColors;
    }

    QString GroupsUiManager::getNationColor(const QString& nationName) const
    {
        if (_nationColors.contains(nationName))
            return _nationColors[nationName];

        std::string errorMessage("Cannot convert nation. Unknown value: " + nationName.toStdString());
        std::cout << errorMessage << std::endl;

        return "#969696";
    }

}