#pragma once

#include <QObject>

#include <character/skill/skill.h>

namespace Ityl::Ui::UiModels
{
    class SkillUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString skillName READ skillName CONSTANT)
        Q_PROPERTY(QString skillValues READ skillValues CONSTANT)

    public:
        explicit SkillUiModel(QObject *parent = nullptr);
        SkillUiModel(const QString &skillName, const QList<DataModel::Skill> &skillValues, QObject *parent = nullptr);

        ~SkillUiModel() override = default;

        QString skillName() const { return _skillName; }
        QString skillValues() const {return _skillValues; }

    signals:

    public slots:

    private:
        QString _skillName;
        QList<DataModel::Skill> _skills;
        QString _skillValues;

        QString createSkillValuesStringFromSkills(const QList<DataModel::Skill>& skills) const;
    };
}
