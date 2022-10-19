#pragma once

#include <QHash>

namespace Ityl::Json
{
    enum class JsonKey
    {
        Character,
        Values,
        FirstName,
        LastName,
        BirthName,
        NickName,
        Title,
        Quote,
        BirthPlace,
        LivelyPlace,
        BirthNation,
        CurrentNation,
        BirthDate,
        DeathDate,
        Status,
        Description,
        Groups,
        Group,
        Type,
        Subgroup,
        Roles,
        Role,
        IsOld,
        Ethnies,
        Ethnie,
        Avatars,
        Organization,
        Family,
        Guild,
        Alive,
        Dead,
        Missing,
        Sealed,
        Skills,
        Relationships
    };

    class JsonModelMapper
    {
    public:
        JsonModelMapper();

        QString get(JsonKey key) const;

    private:
        QHash<JsonKey, QString> _keys;
    };
}
