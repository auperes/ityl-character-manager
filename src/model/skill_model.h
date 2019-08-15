#pragma once

#include <memory>

#include <QAbstractListModel>
#include <QMap>
#include <QList>
#include <QString>

#include "qObjectWrapper/skills_wrapper.h"
#include "../dataModel/skill/skill.h"

class SkillModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(std::shared_ptr<SkillsWrapper> skills READ skills WRITE setSkills)

public:
    explicit SkillModel(QObject *parent = nullptr);

    enum {
        SkillNameRole = Qt::UserRole,
        SkillValuesRole,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    std::shared_ptr<SkillsWrapper> skills() const;
    void setSkills(std::shared_ptr<SkillsWrapper> skillsWrapper);

private:
    std::shared_ptr<SkillsWrapper> _skillsWrapper;

    QString convertIntSkillNameToString(int value) const;
    QString createSkillValuesStringFromSkills(const QList<Skill>& skills) const;
};
