#pragma once

#include <QObject>

#include "../character/characters_ui_manager.h"
#include "group_ui_model.h"
#include "../../provider/groups_provider.h"

namespace Ityl::UiModel
{
    class GroupsUiManager : public QObject
    {
        Q_OBJECT
    public:
        GroupsUiManager(const QString& groupsFolderPath, const QMap<QString, QString>& nationColors, CharactersUiManager* characterUiManager, QObject *parent = nullptr);

        Q_INVOKABLE GroupUiModel* addGroup(const QString& name);
        Q_INVOKABLE void removeGroup(unsigned id);

    signals:

    public slots:
        void refreshGroups();
        void changeGroupsLocation(const QString& folderPath);
        void changeNationColors(const QMap<QString, QString>& nationColors);

    private:
        unsigned _idSequence = 0;
        Provider::GroupsProvider _groupsProvider;
        QMap<unsigned, std::shared_ptr<UiModel::GroupUiModel>> _groupUiModels;
        QMap<QString, QString> _nationColors;
        CharactersUiManager* _characterUiManager; //TODO get CharacterUiCollections without CharacterUiManager

        QMap<QString, std::shared_ptr<GroupPartUiModel>> getPartUiModelsByName(const GroupUiModel& groupUiModel) const;
        QMap<QString, std::shared_ptr<GroupPartUiModel>> getPartUiModelsByName(const QList<std::shared_ptr<GroupPartUiModel>>& partUiModels) const;
        QString getNationColor(const QString& nationName) const;
    };
}
