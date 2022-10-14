#pragma once

#include <memory>

#include <QAbstractItemModel>
#include <QObject>
#include <QUrl>

#include "skill_ui_model.h"
#include "relationship_ui_model.h"
#include "../group/group_info_ui_model.h"

namespace Ityl::UI
{
    class CharacterUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString fullName READ fullName CONSTANT)
        Q_PROPERTY(QUrl avatar READ avatar CONSTANT)
        Q_PROPERTY(QUrl miniAvatar READ miniAvatar CONSTANT)
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

        ~CharacterUiModel() override = default;

        const QString fullName() const { return _fullName; }
        const QUrl avatar() const { return _avatar; }
        const QUrl miniAvatar() const { return _miniAvatar; }
        const QString quote() const { return _quote; }
        const QString& title() const { return _title; }
        const QString birthPlace() const { return "Lieu de naissance : " + _birthPlace; }
        const QString livelyPlace() const { return "Lieu de vie : " + _livelyPlace; }
        const QString& description() const { return _description; }
        const QStringList roles() const { return _roles.toList(); }
        QAbstractItemModel* skills() const { return _skills.get(); }
        QAbstractItemModel* relationships() const { return _relationships.get(); }
        const QStringList ethnies() const { return _ethnies; }
        QAbstractItemModel* groups() const { return _groups.get(); }
        const QString nationColor() const { return _nationColor; }
        bool hasTitle() const { return !_title.isEmpty(); };

    signals:

    public slots:

    private:
        QString _fullName;
        QUrl _avatar;
        QUrl _miniAvatar;
        QString _title;
        QString _quote;
        QString _birthPlace;
        QString _livelyPlace;
        QString _description;
        QStringList _roles;
        std::unique_ptr<QAbstractItemModel> _skills;
        QList<std::shared_ptr<SkillUiModel>> _skillUiModels;

        std::unique_ptr<QAbstractItemModel> _relationships;
        QList<std::shared_ptr<RelationshipUiModel>> _relationshipUiModels;

        QList<QString> _ethnies;
        std::unique_ptr<QAbstractItemModel> _groups;
        QList<std::shared_ptr<GroupInfoUiModel>> _groupInfoUiModels;

        QString _nationColor;

        void addSkill(std::shared_ptr<SkillUiModel> skill);
        void addRelationship(std::shared_ptr<RelationshipUiModel> relationship);
        void addGroup(std::shared_ptr<GroupInfoUiModel> groupInfo);
        QUrl loadImage(QString name, QString path, QString type) const;
    };
}
