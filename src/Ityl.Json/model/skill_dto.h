#pragma once

#include <QJsonObject>
#include <QString>
#include <QVector>

namespace Ityl::Json
{
    class SkillDto
    {
    public:
        SkillDto() = default;

        const QString& getCategory() const;
        void setCategory(const QString& category);
        const QString& getName() const;
        void setName(const QString& name);
        const QVector<QString>& getSpecialities() const;
        void setSpecialities(const QVector<QString>& specialities);

        void read(const QJsonObject& json);
        void write(QJsonObject& json);

    private:
        QString _category;
        QString _name;
        QVector<QString> _specialities;
    };
}
