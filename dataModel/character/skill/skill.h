#pragma once

#include <QString>
#include <QVector>

namespace Ityl::DataModel
{
    class Skill
    {
    public:
        Skill();
        Skill(const QString& type);
        Skill(const QString& type, QVector<QString>&& specialties);

        QString getType()const  { return _type; }
        QVector<QString> getSpecialties()const  { return _specialties; }

        void setType(const QString& type) { _type = type; }
        void setSpecialties(const QVector<QString>& specialties) { _specialties = specialties; }
        void setSpecialties(QVector<QString>&& specialties) { _specialties = specialties; }

    private:
        QString _type;
        QVector<QString> _specialties;
    };
}
