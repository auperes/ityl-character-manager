#pragma once

#include <memory>

#include <QAbstractItemModel>
#include <QObject>

#include "../dataModel/character/character.h"
#include "relationship_ui_model.h"
#include "skill_ui_model.h"

class CharacterUiModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fullName READ fullName CONSTANT)
    Q_PROPERTY(QString avatar READ avatar CONSTANT)
    Q_PROPERTY(QString title READ title CONSTANT)
    Q_PROPERTY(QString quote READ quote CONSTANT)
    Q_PROPERTY(QString birthPlace READ birthPlace CONSTANT)
    Q_PROPERTY(QString livelyPlace READ livelyPlace CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QStringList roles READ roles CONSTANT)
    Q_PROPERTY(QAbstractItemModel* skills READ skills CONSTANT)
    Q_PROPERTY(QAbstractItemModel* relationships READ relationships CONSTANT)
    Q_PROPERTY(QStringList ethnies READ ethnies CONSTANT)
    Q_PROPERTY(QStringList groups READ groups CONSTANT)
    Q_PROPERTY(QString nationColor READ nationColor CONSTANT)
    Q_PROPERTY(bool hasTitle READ hasTitle CONSTANT)


public:
    CharacterUiModel();
    explicit CharacterUiModel(const std::shared_ptr<Character> &character);
    explicit CharacterUiModel(const CharacterUiModel &characterUiModel);

    const QString fullName() const;
    const QString avatar() const;
    const QString quote() const;
    const QString& title() const { return _character->getTitle(); }
    const QString birthPlace() const { return "Lieu de naissance : " + _character->getBirthPlace(); }
    const QString livelyPlace() const { return "Lieu de vie : " + _character->getLivelyPlace(); }
    const QString& description() const { return _character->getDescription(); }
    const QStringList roles() const { return _character->getRoles().toList(); }
    QAbstractItemModel* skills() const { return _skills.get(); }
    QAbstractItemModel* relationships() const { return _relationships.get(); }
    const QStringList ethnies() const { return _character->getEthnies().toList(); }
    const QStringList groups() const { return _character->getGroups().toList(); }
    const QString nationColor() const;
    bool hasTitle() const;

signals:

public slots:

private:
    std::shared_ptr<Character> _character;
    std::unique_ptr<QAbstractItemModel> _skills;
    std::unique_ptr<QAbstractItemModel> _relationships;
    QList<std::shared_ptr<SkillUiModel>> _skillUiModels;
    QList<std::shared_ptr<RelationshipUiModel>> _relationshipUiModels;

    void addSkill(const QString& skillName, const QList<Skill>& skillValues);
    void addRelationship(const Relationship& relationType, const QList<QPair<QString, QString>> &characterNames);
};

