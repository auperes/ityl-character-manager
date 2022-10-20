#include "json_model_mapper.h"

namespace Ityl::Json
{
    JsonModelMapper::JsonModelMapper()
    {
        _keys.emplace(JsonKey::FirstName, "firstName");
        _keys.emplace(JsonKey::LastName, "lastName");
        _keys.emplace(JsonKey::BirthName, "birthName");
        _keys.emplace(JsonKey::NickName, "nickName");
        _keys.emplace(JsonKey::Title, "title");
        _keys.emplace(JsonKey::Quote, "quote");
        _keys.emplace(JsonKey::BirthPlace, "birthPlace");
        _keys.emplace(JsonKey::LivelyPlace, "livelyPlace");
        _keys.emplace(JsonKey::BirthNation, "birthNation");
        _keys.emplace(JsonKey::CurrentNation, "currentNation");
        _keys.emplace(JsonKey::BirthDate, "birthDate");
        _keys.emplace(JsonKey::DeathDate, "deathDate");
        _keys.emplace(JsonKey::Status, "status");
        _keys.emplace(JsonKey::Description, "description");
        _keys.emplace(JsonKey::Group, "group");
        _keys.emplace(JsonKey::Type, "type");
        _keys.emplace(JsonKey::Subgroup, "subgroup");
        _keys.emplace(JsonKey::Role, "role");
        _keys.emplace(JsonKey::IsOld, "old");
        _keys.emplace(JsonKey::Ethnie, "ethnie");
        _keys.emplace(JsonKey::Organization, "organization");
        _keys.emplace(JsonKey::Family, "family");
        _keys.emplace(JsonKey::Guild, "guild");
        _keys.emplace(JsonKey::Alive, "alive");
        _keys.emplace(JsonKey::Dead, "dead");
        _keys.emplace(JsonKey::Missing, "missing");
        _keys.emplace(JsonKey::Sealed, "sealed");
        _keys.emplace(JsonKey::Character, "character");
        _keys.emplace(JsonKey::Values, "values");
        _keys.emplace(JsonKey::Roles, "roles");
        _keys.emplace(JsonKey::Skills, "skills");
        _keys.emplace(JsonKey::Relationships, "relationships");
        _keys.emplace(JsonKey::Ethnies, "ethnies");
        _keys.emplace(JsonKey::Groups, "groups");
        _keys.emplace(JsonKey::Avatars, "avatars");
        _keys.emplace(JsonKey::Avatar, "avatar");
        _keys.emplace(JsonKey::IsMiniAvatar, "isMiniAvatar");
    }

    QString JsonModelMapper::get(JsonKey key) const
    {
        return _keys[key];
    }
}
