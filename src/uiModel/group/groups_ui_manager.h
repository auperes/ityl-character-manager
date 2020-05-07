#pragma once

#include <QObject>

#include "group_ui_model.h"
#include "../../provider/groups_provider.h"

namespace Ityl::UiModel
{
    class GroupsUiManager : public QObject
    {
        Q_OBJECT
    public:
        GroupsUiManager(const QString& groupsFolderPath, const QMap<QString, QString>& nationColors, QObject *parent = nullptr);

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



    };
}
