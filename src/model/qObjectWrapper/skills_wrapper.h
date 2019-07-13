#pragma once

#include <QObject>
#include <QMap>
#include <QString>

#include "../../dataModel/skill/skill.h"

class SkillsWrapper : public QObject
{
    Q_OBJECT
public:
    explicit SkillsWrapper(QObject *parent = nullptr);
    SkillsWrapper(const QMap<QString, QList<Skill> > &skills, QObject *parent = nullptr);
    SkillsWrapper(const SkillsWrapper& skillsWrapper);

    QMap<QString, QList<Skill> > skills() const;

signals:

public slots:

private:
    QMap<QString, QList<Skill>> _skills;
};
