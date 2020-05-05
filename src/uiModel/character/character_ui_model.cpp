#include "character_ui_model.h"

#include <iostream>

#include <QDir>
#include <QQmlEngine>
#include <QStandardItemModel>
#include <QMap>

#include "../../converters/converters.h"
#include "../../dataModel/app_config.h"

namespace Ityl::UiModel
{
    CharacterUiModel::CharacterUiModel()
        : QObject ()
        , _character(nullptr)
        , _skills(nullptr)
        , _relationships(nullptr)
        , _groups(nullptr)
    {

    }

    CharacterUiModel::CharacterUiModel(const std::shared_ptr<DataModel::Character> &character, const QString& nationColor)
        : QObject()
        , _character(character)
        , _skills(new QStandardItemModel(this))
        , _relationships(new QStandardItemModel(this))
        , _nationColor(nationColor)
        , _groups(new QStandardItemModel(this))
    {
        _skills->insertColumn(0);

        auto skills = _character->getSkills();
        for (auto skillName : skills.keys())
            addSkill(skillName, skills.value(skillName));

        _relationships->insertColumn(0);

        auto relationships = _character->getRelationships();
        for (auto relationship : relationships.keys())
            addRelationship(relationship, relationships.value(relationship));

        _groups->insertColumn(0);

        auto groups = _character->getGroups();
        for (auto group : groups)
            addGroup(group);

        _ethnies.reserve(_character->getEthnies().size());
        for (const auto& ethnie : _character->getEthnies())
            _ethnies.push_back(ethnie.getName());

    }

    CharacterUiModel::CharacterUiModel(const CharacterUiModel &characterUiModel, const QString& nationColor)
        : QObject()
        , _character(characterUiModel._character)
        , _nationColor(nationColor)
    {

    }

    const QString CharacterUiModel::fullName() const
    {
        return _character->getFirstName() + " " + _character->getLastName();
    }

    const QUrl CharacterUiModel::avatar() const
    {
        if (_character->getAvatars().isEmpty())
        {
            std::cout << "Character " + _character->getFirstName().toStdString() + " " + _character->getLastName().toStdString() + " has no avatar" << std::endl;
            return QUrl();
        }

        QUrl avatarFolderUrl("file:///" + DataModel::AppConfig::getAvatarsFolderPath() + _character->getAvatars().first());
        if (QDir(DataModel::AppConfig::getAvatarsFolderPath()).isRelative())
            return QUrl("file:///" + QDir::currentPath() + "/" + DataModel::AppConfig::getAvatarsFolderPath() + _character->getAvatars().first());

        return QUrl("file:///" + DataModel::AppConfig::getAvatarsFolderPath() + _character->getAvatars().first());
    }

    const QString CharacterUiModel::quote() const
    {
        return "« " + _character->getQuote() + " »";
    }

    bool CharacterUiModel::hasTitle() const
    {
        return _character->getTitle().size() > 0;
    }

    void CharacterUiModel::addSkill(const QString &skillName, const QList<DataModel::Skill> &skillValues)
    {
        const int newRow = _skills->rowCount();
        std::shared_ptr<SkillUiModel> skillUi = std::make_shared<SkillUiModel>(skillName, skillValues);
        QQmlEngine::setObjectOwnership(skillUi.get(), QQmlEngine::CppOwnership);
        _skills->insertRow(newRow);
        _skills->setData(_skills->index(newRow, 0), QVariant::fromValue(skillUi.get()), Qt::DisplayRole);
        _skillUiModels.push_back(std::move(skillUi));
    }

    void CharacterUiModel::addRelationship(const DataModel::Relationship &relationType, const QList<QPair<QString, QString>> &characterNames)
    {
        const int newRow = _relationships->rowCount();
        std::shared_ptr<RelationshipUiModel> relationshipUi = std::make_shared<RelationshipUiModel>(relationType, characterNames);
        QQmlEngine::setObjectOwnership(relationshipUi.get(), QQmlEngine::CppOwnership);
        _relationships->insertRow(newRow);
        _relationships->setData(_relationships->index(newRow, 0), QVariant::fromValue(relationshipUi.get()), Qt::DisplayRole);
        _relationshipUiModels.push_back(std::move(relationshipUi));
    }

    void CharacterUiModel::addGroup(const DataModel::GroupInfo& groupInfo)
    {
        const int newRow = _groups->rowCount();
        std::shared_ptr<GroupInfoUiModel> groupInfoUi = std::make_shared<GroupInfoUiModel>(groupInfo);
        QQmlEngine::setObjectOwnership(groupInfoUi.get(), QQmlEngine::CppOwnership);
        _groups->insertRow(newRow);
        _groups->setData(_groups->index(newRow, 0), QVariant::fromValue(groupInfoUi.get()), Qt::DisplayRole);
        _groupInfoUiModels.push_back(std::move(groupInfoUi));
    }
}
