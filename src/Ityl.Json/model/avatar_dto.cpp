#include "avatar_dto.h"

namespace Ityl::Json
{
    AvatarDto::AvatarDto()
    {

    }

    const QHash<QString, QVariant>& AvatarDto::getValues() const
    {
        return _values;
    }

    void AvatarDto::read(const QJsonObject& json)
    {
        for (auto it = json.begin(); it != json.end(); it++)
            _values.emplace(it.key(), it.value().toVariant());
    }

    void AvatarDto::write(QJsonObject& json)
    {

    }
}
