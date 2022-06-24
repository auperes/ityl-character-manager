#pragma once

#include <QObject>

#include <providers/groups_provider.h>

#include "../character/characters_ui_manager.h"
#include "group_ui_model.h"

namespace Ityl::Ui::UiModels
{
    class GroupsUiManager : public QObject
    {
        Q_OBJECT
    public:
        GroupsUiManager(const QString& groupsFolderPath, const QMap<QString, QString>& nationColors, CharactersUiManager* characterUiManager, QObject *parent = nullptr);

        ~GroupsUiManager() override = default;

        std::shared_ptr<GroupUiModel> createGroup(const QString& name);

    signals:

    public slots:
        void changeGroupsLocation(const QString& folderPath);
        void changeNationColors(const QMap<QString, QString>& nationColors);

    private:
        Business::Providers::GroupsProvider _groupsProvider;
        QMap<QString, QString> _nationColors;
        CharactersUiManager* _characterUiManager; //TODO get CharacterUiCollections without CharacterUiManager

        QString getNationColor(const QString& nationName) const;

        std::shared_ptr<GroupUiModel> createGroupUiModelFromGroup(const QString& groupName, const std::shared_ptr<DataModel::Group>& group);
        std::shared_ptr<GroupUiModel> createGroupUiModelFromEthnie(const QString& ethnieName, const std::shared_ptr<DataModel::Group>& group);
    };
}
