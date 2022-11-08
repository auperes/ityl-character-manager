#include "skill_dto.h"

#include <QJsonArray>

namespace Ityl::Json
{
    const QString& SkillDto::getCategory() const
    {
        return _category;
    }

    void SkillDto::setCategory(const QString& category)
    {
        _category = category;
    }

    const QString& SkillDto::getName() const
    {
        return _name;
    }

    void SkillDto::setName(const QString& name)
    {
        _name = name;
    }

    const QVector<QString>& SkillDto::getSpecialities() const
    {
        return _specialities;
    }

    void SkillDto::setSpecialities(const QVector<QString>& specialities)
    {
        _specialities = specialities;
    }

    void SkillDto::read(const QJsonObject& json)
    {
        _category = json["category"].toString();
        _name = json["name"].toString();

        if (json.contains("specialties"))
        {
            QJsonArray specialtiesJson = json["specialties"].toArray();
            _specialities.reserve(specialtiesJson.size());

            for (auto specialty : specialtiesJson)
            {
                QJsonObject specialtyObject = specialty.toObject();
                _specialities.push_back(specialtyObject["specialty"].toString());
            }
        }
    }

    void SkillDto::write(QJsonObject& json)
    {

    }
}
