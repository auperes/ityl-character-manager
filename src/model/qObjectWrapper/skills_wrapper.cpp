#include "skills_wrapper.h"

SkillsWrapper::SkillsWrapper(QObject *parent)
    : QObject (parent)
    , _skills()
{

}

SkillsWrapper::SkillsWrapper(const QMap<QString, QList<Skill> > &skills, QObject *parent)
    :  QObject(parent)
    , _skills(skills)
{

}

SkillsWrapper::SkillsWrapper(const SkillsWrapper &skillsWrapper)
    : QObject(skillsWrapper.parent())
    , _skills(skillsWrapper.skills())
{

}

QMap<QString, QList<Skill> > SkillsWrapper::skills() const
{
    return _skills;
}
