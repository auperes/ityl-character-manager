#include "character_adapter.h"

#include <iostream>
#include <string>
#include <QString>

namespace Ityl::Json
{
    CharacterAdapter::CharacterAdapter(std::shared_ptr<JsonModelMapper> mapper)
        : _mapper(mapper)
    {
    }

    Core::Character CharacterAdapter::toCharacter(const CharacterDto& characterDto)
    {
        Core::Character character;
        character
                .setFirstName(characterDto.getValues().value(_mapper->get(JsonKey::FirstName)).toStdString())
                .setLastName(characterDto.getValues().value(_mapper->get(JsonKey::LastName)).toStdString())
                .setBirthName(characterDto.getValues().value(_mapper->get(JsonKey::BirthName)).toStdString())
                .setNickName(characterDto.getValues().value(_mapper->get(JsonKey::NickName)).toStdString())
                .setTitle(characterDto.getValues().value(_mapper->get(JsonKey::Title)).toStdString())
                .setQuote(characterDto.getValues().value(_mapper->get(JsonKey::Quote)).toStdString())
                .setBirthPlace(characterDto.getValues().value(_mapper->get(JsonKey::BirthPlace)).toStdString())
                .setLivelyPlace(characterDto.getValues().value(_mapper->get(JsonKey::LivelyPlace)).toStdString())
                .setBirthNation(characterDto.getValues().value(_mapper->get(JsonKey::BirthNation)).toStdString())
                .setCurrentNation(characterDto.getValues().value(_mapper->get(JsonKey::CurrentNation)).toStdString())
                .setStatus(toStatus(characterDto.getValues().value(_mapper->get(JsonKey::Status))))
                .setDescription(characterDto.getValues().value(_mapper->get(JsonKey::Description)).toStdString())
                .setRoles(toRoles(characterDto.getRoles()))
//                .setSkills(toSkills(characterDto.getSkills()))
//                .setRelationships(toRelationships(characterDto.getRelationships()))
                .setEthnies(toEthnies(characterDto.getEthnies()))
                .setGroups(toGroups(characterDto.getGroups()))
                .setMiniAvatar(toMiniAvatar(characterDto.getAvatars()))
                .setAvatars(toAvatars(characterDto.getAvatars()));

        return character;
    }

    CharacterDto CharacterAdapter::toCharacterDto(const Core::Character& character)
    {
        throw std::runtime_error("Not implemented");
    }

    std::string CharacterAdapter::toAvatar(const AvatarDto& avatarDto)
    {
        throw std::runtime_error("Not implemented");
    }

    AvatarDto CharacterAdapter::toAvatarDto(const std::string& avatar)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<std::string> CharacterAdapter::toAvatars(const QVector<AvatarDto>& avatarDtos)
    {
        std::vector<std::string> avatars;
        avatars.reserve(avatarDtos.size());

        for (const auto& dto : avatarDtos)
            avatars.push_back(dto.getValues()[_mapper->get(JsonKey::Avatar)].toString().toStdString());

        return avatars;
    }

    QVector<AvatarDto> CharacterAdapter::toAvatarDtos(std::vector<std::string> avatars)
    {
        throw std::runtime_error("Not implemented");
    }

    std::string CharacterAdapter::toMiniAvatar(const QVector<AvatarDto>& avatarDtos)
    {
        auto it = std::find_if(avatarDtos.begin(),
                               avatarDtos.end(),
                               [this](const auto& dto)
        {
            return dto.getValues().contains(_mapper->get(JsonKey::IsMiniAvatar))
                    && dto.getValues()[_mapper->get(JsonKey::IsMiniAvatar)].toBool();
        });

        if (it != avatarDtos.end())
            return it->getValues()[_mapper->get(JsonKey::Avatar)].toString().toStdString();

        return {};
    }

    Core::GroupInfo CharacterAdapter::toGroup(GroupDto groupDto)
    {
        Core::GroupInfo groupInfo;
        const auto& values = groupDto.getValues();
        if (values.contains(_mapper->get(JsonKey::Group)))
            groupInfo.setName(values[_mapper->get(JsonKey::Group)].toString().toStdString());
        if (values.contains(_mapper->get(JsonKey::Type)))
            groupInfo.setType(toGroupType(values[_mapper->get(JsonKey::Type)].toString()));
        if (values.contains(_mapper->get(JsonKey::Subgroup)))
            groupInfo.setSubgroupName(values[_mapper->get(JsonKey::Subgroup)].toString().toStdString());
        if (values.contains(_mapper->get(JsonKey::Role)))
            groupInfo.setRole(values[_mapper->get(JsonKey::Role)].toString().toStdString());
        if (values.contains(_mapper->get(JsonKey::IsOld)))
            groupInfo.setIsOld(QVariant(values[_mapper->get(JsonKey::IsOld)]).toBool());

        return groupInfo;
    }

    GroupDto CharacterAdapter::toGroupDto(const Core::GroupInfo& group)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<Core::GroupInfo> CharacterAdapter::toGroups(const QVector<GroupDto>& groupDtos)
    {
        std::vector<Core::GroupInfo> groups;
        groups.reserve(groupDtos.size());

        for (const auto& groupDto : groupDtos)
            groups.push_back(toGroup(groupDto));

        return groups;
    }

    QVector<GroupDto> CharacterAdapter::toGroupDtos(const std::vector<Core::GroupInfo>& groups)
    {
        throw std::runtime_error("Not implemented");
    }

    Core::GroupType CharacterAdapter::toGroupType(const QString& typeDto)
    {
        if (typeDto == _mapper->get(JsonKey::Ethnie))
            return Core::GroupType::Ethnie;
        if (typeDto == _mapper->get(JsonKey::Family))
            return Core::GroupType::Family;
        if (typeDto == _mapper->get(JsonKey::Organization))
            return Core::GroupType::Organization;
        if (typeDto == _mapper->get(JsonKey::Guild))
            return Core::GroupType::Guild;
        if (typeDto == _mapper->get(JsonKey::Group))
            return Core::GroupType::Group;

        throw std::runtime_error("Unsupported GroupType " + typeDto.toStdString());
    }

    QString CharacterAdapter::toGroupTypeDto(const Core::GroupType& type)
    {
        throw std::runtime_error("Not implemented");
    }

    Core::GroupInfo CharacterAdapter::toEthnie(QString ethnieDto)
    {
        Core::GroupInfo ethnie(ethnieDto.toStdString());
        ethnie.setType(Core::GroupType::Ethnie);
        return ethnie;
    }

    QString CharacterAdapter::toEthnieDto(const Core::GroupInfo& ethnie)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<Core::GroupInfo> CharacterAdapter::toEthnies(const QVector<QString>& ethnieDtos)
    {
        std::vector<Core::GroupInfo> ethnies;
        ethnies.reserve(ethnieDtos.size());

        for (const auto& ethnieDto : ethnieDtos)
            ethnies.push_back(toEthnie(ethnieDto));

        return ethnies;
    }

    QVector<QString> CharacterAdapter::toEthnieDtos(const std::vector<Core::GroupInfo>& ethnies)
    {
        throw std::runtime_error("Not implemented");
    }

    std::unordered_map<Core::Relationship, std::vector<std::pair<std::string, std::string> > > CharacterAdapter::toRelationships(const QVector<RelationshipDto>& relationshipDtos)
    {
        throw std::runtime_error("Not implemented");
    }

    QVector<RelationshipDto> CharacterAdapter::toRelationshipDtos(const std::unordered_map<Core::Relationship, std::vector<std::pair<std::string, std::string> > >& relationships)
    {
        throw std::runtime_error("Not implemented");
    }

    std::string CharacterAdapter::toRole(QString roleDto)
    {
        return roleDto.toStdString();
    }

    QString CharacterAdapter::toRoleDto(const std::string& role)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<std::string> CharacterAdapter::toRoles(const QVector<QString>& roleDtos)
    {
        std::vector<std::string> roles;
        roles.reserve(roleDtos.size());

        for (const auto& roleDto : roleDtos)
            roles.push_back(toRole(roleDto));

        return roles;
    }

    QVector<QString> CharacterAdapter::toRoleDtos(const std::vector<std::string>& roles)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<Core::Skill> CharacterAdapter::toSkill(SkillDto skillDto)
    {
        throw std::runtime_error("Not implemented");
    }

    SkillDto CharacterAdapter::toSkillDto(const std::vector<Core::Skill>& skill)
    {
        throw std::runtime_error("Not implemented");
    }

    std::unordered_map<std::string, std::vector<Core::Skill> > CharacterAdapter::toSkills(const QVector<SkillDto>& skillDtos)
    {
        throw std::runtime_error("Not implemented");
    }

    QVector<SkillDto> CharacterAdapter::toSkillDtos(const std::unordered_map<std::string, std::vector<Core::Skill> >& skills)
    {
        throw std::runtime_error("Not implemented");
    }

    Core::Status CharacterAdapter::toStatus(QString statusDto)
    {
        if (statusDto == _mapper->get(JsonKey::Alive))
            return Core::Status::Alive;
        if (statusDto == _mapper->get(JsonKey::Dead))
            return Core::Status::Dead;
        if (statusDto == _mapper->get(JsonKey::Missing))
            return Core::Status::Missing;
        if (statusDto == _mapper->get(JsonKey::Sealed))
            return Core::Status::Sealed;

        std::string errorMessage("Cannot convert status. Unknown value: " + _mapper->get(JsonKey::Status).toStdString());
        std::cout << errorMessage << std::endl;
        throw std::logic_error(errorMessage.c_str());
    }

    QString CharacterAdapter::toStatusDto(const Core::Status& status)
    {
        throw std::runtime_error("Not implemented");
    }
}
