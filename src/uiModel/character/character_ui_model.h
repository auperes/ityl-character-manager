#pragma once

#include <memory>

#include <QAbstractItemModel>
#include <QObject>
#include <QUrl>

#include "../../dataModel/character/character.h"
#include "relationship_ui_model.h"
#include "skill_ui_model.h"
#include "../group/group_info_ui_model.h"

namespace Ityl::UiModel
{
    class CharacterUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString fullName READ fullName CONSTANT)
        Q_PROPERTY(QUrl avatar READ avatar CONSTANT)
        Q_PROPERTY(QString title READ title CONSTANT)
        Q_PROPERTY(QString quote READ quote CONSTANT)
        Q_PROPERTY(QString birthPlace READ birthPlace CONSTANT)
        Q_PROPERTY(QString livelyPlace READ livelyPlace CONSTANT)
        Q_PROPERTY(QString description READ description CONSTANT)
        Q_PROPERTY(QStringList roles READ roles CONSTANT)
        Q_PROPERTY(QAbstractItemModel* skills READ skills CONSTANT)
        Q_PROPERTY(QAbstractItemModel* relationships READ relationships CONSTANT)
        Q_PROPERTY(QStringList ethnies READ ethnies CONSTANT)
        Q_PROPERTY(QAbstractItemModel* groups READ groups CONSTANT)
        Q_PROPERTY(QString nationColor READ nationColor CONSTANT)
        Q_PROPERTY(bool hasTitle READ hasTitle CONSTANT)


    public:
        CharacterUiModel();
        explicit CharacterUiModel(const std::shared_ptr<DataModel::Character> &character, const QString& nationColor);
        explicit CharacterUiModel(const CharacterUiModel &characterUiModel, const QString& nationColor);

        const QString fullName() const;
        const QUrl avatar() const;
        const QString quote() const;
        const QString& title() const { return _character->getTitle(); }
        const QString birthPlace() const { return "Lieu de naissance : " + _character->getBirthPlace(); }
        const QString livelyPlace() const { return "Lieu de vie : " + _character->getLivelyPlace(); }
        const QString& description() const { return _character->getDescription(); }
        const QStringList roles() const { return _character->getRoles().toList(); }
        QAbstractItemModel* skills() const { return _skills.get(); }
        QAbstractItemModel* relationships() const { return _relationships.get(); }
        const QStringList ethnies() const { return _ethnies; }
        QAbstractItemModel* groups() const { return _groups.get(); }
        const QString nationColor() const { return _nationColor; }
        bool hasTitle() const;

    signals:

    public slots:

    private:
        std::shared_ptr<DataModel::Character> _character;
        std::unique_ptr<QAbstractItemModel> _skills;
        std::unique_ptr<QAbstractItemModel> _relationships;
        QList<std::shared_ptr<SkillUiModel>> _skillUiModels;
        QList<std::shared_ptr<RelationshipUiModel>> _relationshipUiModels;
        QString _nationColor;
        QList<QString> _ethnies;
        std::unique_ptr<QAbstractItemModel> _groups;
        QList<std::shared_ptr<GroupInfoUiModel>> _groupInfoUiModels;

        void addSkill(const QString& skillName, const QList<DataModel::Skill>& skillValues);
        void addRelationship(const DataModel::Relationship& relationType, const QList<QPair<QString, QString>> &characterNames);
        void addGroup(const DataModel::GroupInfo& groupInfo);
    };
}
