#include "group_dto.h"

namespace Ityl::Json
{
    GroupDto::GroupDto()
    {
        
    }

    const QHash<QString, QVariant>& GroupDto::getValues() const
    {
        return _values;
    }
    
    void GroupDto::read(const QJsonObject& json)
    {
        for (auto it = json.begin(); it != json.end(); it++)
            _values.emplace(it.key(), it.value().toVariant());
    }
    
    void GroupDto::write(QJsonObject& json)
    {

    }
}
