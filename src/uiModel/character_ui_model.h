#pragma once

#include <QObject>

#include "../dataModel/character.h"

class CharacterUiModel
{
    Q_GADGET
    Q_PROPERTY(QString fullName READ fullName CONSTANT)
    Q_PROPERTY(QString avatar READ avatar CONSTANT)
    Q_PROPERTY(QString title READ title CONSTANT)
    Q_PROPERTY(QString quote READ quote CONSTANT)
    Q_PROPERTY(QString birthPlace READ birthPlace CONSTANT)
    Q_PROPERTY(QString livelyPlace READ livelyPlace CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
//    Q_PROPERTY(roles)
//    Q_PROPERTY(skills)
//    Q_PROPERTY(relationships)
//    Q_PROPERTY(ethnies)
//    Q_PROPERTY(groups)


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

signals:

public slots:

private:
    std::shared_ptr<Character> _character;
};

