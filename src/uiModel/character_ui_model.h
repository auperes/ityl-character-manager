#pragma once

#include <memory>

#include <QAbstractItemModel>
#include <QObject>

#include "../dataModel/character.h"

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


public:
    CharacterUiModel();
    explicit CharacterUiModel(const std::shared_ptr<Character> &character);
    explicit CharacterUiModel(const CharacterUiModel &characterUiModel);

    const QString fullName() const;
    const QString avatar() const;
    const QString quote() const;
    const QString& title() const { return _character->getTitle(); }
    const QString& birthPlace() const { return _character->getBirthPlace(); }
    const QString& livelyPlace() const { return _character->getLivelyPlace(); }
    const QString& description() const { return _character->getDescription(); }
    const QStringList roles() const { return _character->getRoles().toList(); }
    QAbstractItemModel* skills() const { return _skills.get(); }
    QAbstractItemModel* relationships() const { return _relationships.get(); }
    const QStringList ethnies() const { return _character->getEthnies().toList(); }
    const QStringList groups() const { return _character->getGroups().toList(); }

signals:

public slots:

private:
    std::shared_ptr<Character> _character;
    std::unique_ptr<QAbstractItemModel> _skills;
    std::unique_ptr<QAbstractItemModel> _relationships;

    void addSkill(const QString& skillName, const QList<Skill>& skillValues);
    void addRelationship(const Relationship& relationType, const QList<QPair<QString, QString>> &characterNames);
};

