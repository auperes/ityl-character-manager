#include "groups_ui_manager.h"

#include <iostream>

#include <QQmlEngine>

namespace Ityl::Ui::UiModels
{

    GroupsUiManager::GroupsUiManager(const QString& groupsFolderPath, const QMap<QString, QString>& nationColors, CharactersUiManager* characterUiManager, QObject* parent)
        : QObject(parent)
        , _groupsProvider(Business::Providers::GroupsProvider(groupsFolderPath))
        , _nationColors(nationColors)
        , _characterUiManager(characterUiManager)
    {
    }

    std::shared_ptr<GroupUiModel> GroupsUiManager::createGroup(const QString& name)
    {
        auto group = _groupsProvider.getGroup(name);

        if (!group)
        {
            std::cout << "The group " << name.toStdString() << " has not been found." << std::endl;
            return nullptr;
        }

        auto groupUiModel = group->getType() == DataModel::GroupType::Ethnie
                ? createGroupUiModelFromEthnie(name, group)
                : createGroupUiModelFromGroup(name, group);

        return groupUiModel;
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

    std::shared_ptr<GroupUiModel> GroupsUiManager::createGroupUiModelFromGroup(const QString& groupName, const std::shared_ptr<DataModel::Group>& group)
    {
        auto collectionsBySubgroup = _characterUiManager->getCollectionsFromGroup(groupName);
        auto groupUiModel = std::make_shared<GroupUiModel>(group, getNationColor(group->getNation()));

        auto& partsBySubgroup = groupUiModel->getPartUiModelsBySubgroupName();

        QList<std::shared_ptr<CharacterUiModel>> missingCurrentCharacters;
        QList<std::shared_ptr<CharacterUiModel>> missingOldCharacters;

        for (const auto& subgroup : collectionsBySubgroup.keys())
        {
            auto& collections = collectionsBySubgroup[subgroup];

            if (partsBySubgroup.contains(subgroup))
            {
                const auto& partUiModel = partsBySubgroup[subgroup];
                partUiModel->setCurrentCharactersUiCollection(collections._currentUiCharacters);
                partUiModel->setOldCharactersUiCollection(collections._oldUiCharacters);
            }
            else
            {
                std::cout << "Missing subgroup " << subgroup.toStdString() << " in group " << groupName.toStdString() << std::endl;
                missingCurrentCharacters.append(collections._currentUiCharacters->getCharacterUiModels());
                missingOldCharacters.append(collections._oldUiCharacters->getCharacterUiModels());
            }
        }

        if (!missingCurrentCharacters.empty() || !missingOldCharacters.empty())
        {
            auto part = std::make_shared<DataModel::GroupPart>(DataModel::Group::RootPartName, DataModel::Group::RootSubgroup);
            groupUiModel->addPart(part);
            const auto& partUiModel = partsBySubgroup[DataModel::Group::RootSubgroup];
            partUiModel->currentCharacters()->addCharacters(missingCurrentCharacters);
            partUiModel->oldCharacters()->addCharacters(missingOldCharacters);
        }

        return groupUiModel;
    }

    std::shared_ptr<GroupUiModel> GroupsUiManager::createGroupUiModelFromEthnie(const QString& ethnieName, const std::shared_ptr<DataModel::Group>& group)
    {
        auto collection = _characterUiManager->getCollectionsFromEthnie(ethnieName);
        auto groupUiModel = std::make_shared<GroupUiModel>(group, getNationColor(group->getNation()));

        if (!collection->getCharacterUiModels().empty())
        {
            auto part = std::make_shared<DataModel::GroupPart>(DataModel::Group::RootPartName, DataModel::Group::RootSubgroup);
            groupUiModel->addPart(part);

            const auto& partUiModel = groupUiModel->getPartUiModelsBySubgroupName()[DataModel::Group::RootSubgroup];
            partUiModel->setCurrentCharactersUiCollection(collection);
        }

        return groupUiModel;
    }

}
