#include "skill.h"

Skill::Skill()
{

}

Skill::Skill(const QString& type)
    : _type(type)
    , _specialties(QVector<QString>{})
{

}

Skill::Skill(const QString& type, QVector<QString>&& specialties)
    : _type(type)
    , _specialties(specialties)
{

}
