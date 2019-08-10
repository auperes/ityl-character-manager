#include "skill_model.h"

SkillModel::SkillModel(QObject *parent)
    : QAbstractListModel(parent)
    , _skillsWrapper(nullptr)
{
}

int SkillModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 3; // _skills->size() should always be equal to 3
}

QVariant SkillModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const QString skillName = convertIntSkillNameToString(index.row());

    switch (role)
    {
    case SkillNameRole:
        return QVariant(skillName);
    case SkillValuesRole:
        const QList<Skill> skills = _skillsWrapper->skills().value(skillName);
        return QVariant(createSkillValuesStringFromSkills(skills));
    }
    return QVariant();
}

QHash<int, QByteArray> SkillModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[SkillNameRole] = "skillName";
    names[SkillValuesRole] = "skillValues";
    return names;
}

std::shared_ptr<SkillsWrapper> SkillModel::skills() const
{
    return _skillsWrapper;
}

void SkillModel::setSkills(std::shared_ptr<SkillsWrapper> skillsWrapper)
{
    beginResetModel();

    if (_skillsWrapper)
        _skillsWrapper->disconnect(this);
    _skillsWrapper = skillsWrapper;

    endResetModel();
}

QString SkillModel::convertIntSkillNameToString(int value) const
{
    if (value == 0)
        return "Prestance";
    else if (value == 1)
        return "Combat";
    else
        return "Spirituel";
}

QString SkillModel::createSkillValuesStringFromSkills(const QList<Skill> &skills) const
{
    QString skillDetail;
    for (auto it  = skills.begin(); it != skills.end(); ++it)
    {
        skillDetail += it->getType();
        if (!it->getSpecialties().empty())
        {
            skillDetail += " (";
            auto specialties = it->getSpecialties();
            for (auto specialtyIt = specialties.begin(); specialtyIt != specialties.end(); ++specialtyIt)
            {
                skillDetail += *specialtyIt;
                if (specialtyIt+1 != specialties.end())
                {
                    skillDetail += ", ";
                }
            }
            skillDetail += ")";
        }
        if (it+1 != skills.end())
        {
            skillDetail += ", ";
        }
    }

    return skillDetail;
}
