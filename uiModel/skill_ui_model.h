#pragma once

#include <QObject>

#include "../dataModel/character/skill/skill.h"

class SkillUiModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString skillName READ skillName CONSTANT)
    Q_PROPERTY(QString skillValues READ skillValues CONSTANT)

public:
    explicit SkillUiModel(QObject *parent = nullptr);
    SkillUiModel(const QString &skillName, const QList<Skill> &skillValues, QObject *parent = nullptr);

    QString skillName() const { return _skillName; }
    QString skillValues() const {return _skillValues; }

signals:

public slots:

private:
    QString _skillName;
    QList<Skill> _skills;
    QString _skillValues;

    QString createSkillValuesStringFromSkills(const QList<Skill>& skills) const;
};

