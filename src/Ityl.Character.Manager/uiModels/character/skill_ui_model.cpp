#include "skill_ui_model.h"

namespace Ityl::Ui::UiModels
{
    SkillUiModel::SkillUiModel(QObject *parent) : QObject(parent)
    {

    }

    SkillUiModel::SkillUiModel(const QString &skillName, const QList<DataModel::Skill> &skillValues, QObject *parent)
        : QObject (parent)
        , _skillName(skillName)
        , _skills(skillValues)
    {
        _skillValues = createSkillValuesStringFromSkills(_skills);
    }

    QString SkillUiModel::createSkillValuesStringFromSkills(const QList<DataModel::Skill> &skills) const
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
}
