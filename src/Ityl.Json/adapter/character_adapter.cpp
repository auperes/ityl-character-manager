#include "character_adapter.h"

#include <iostream>
#include <string>
#include <QString>

namespace Ityl::Json
{
    const QString CharacterAdapter::firstNameKey = "firstName";
    const QString CharacterAdapter::lastNameKey = "lastName";
    const QString CharacterAdapter::birthName = "birthName";
    const QString CharacterAdapter::nickName = "nickName";
    const QString CharacterAdapter::title = "title";
    const QString CharacterAdapter::quote = "quote";
    const QString CharacterAdapter::birthPlace = "birthPlace";
    const QString CharacterAdapter::livelyPlace = "livelyPlace";
    const QString CharacterAdapter::birthNation = "birthNation";
    const QString CharacterAdapter::currentNation = "currentNation";
    const QString CharacterAdapter::birthDate = "birthDate";
    const QString CharacterAdapter::deathDate = "deathDate";
    const QString CharacterAdapter::status = "status";
    const QString CharacterAdapter::description = "description";

    const QString CharacterAdapter::group = "group";
    const QString CharacterAdapter::type = "type";
    const QString CharacterAdapter::subgroup = "subgroup";
    const QString CharacterAdapter::role = "role";
    const QString CharacterAdapter::isOld = "old";

    const QString CharacterAdapter::ethnieKey = "ethnie";
    const QString CharacterAdapter::organizationKey = "organization";
    const QString CharacterAdapter::familyKey = "family";
    const QString CharacterAdapter::guildKey = "guild";
    const QString CharacterAdapter::groupKey = "group";

    Core::Character CharacterAdapter::toCharacter(const CharacterDto& characterDto)
    {
        Core::Character character;
        character
                .setFirstName(characterDto.getValues().value(firstNameKey).toStdString())
                .setLastName(characterDto.getValues().value(lastNameKey).toStdString())
                .setBirthName(characterDto.getValues().value(birthName).toStdString())
                .setNickName(characterDto.getValues().value(nickName).toStdString())
                .setTitle(characterDto.getValues().value(title).toStdString())
                .setQuote(characterDto.getValues().value(quote).toStdString())
                .setBirthPlace(characterDto.getValues().value(birthPlace).toStdString())
                .setLivelyPlace(characterDto.getValues().value(livelyPlace).toStdString())
                .setBirthNation(characterDto.getValues().value(birthNation).toStdString())
                .setCurrentNation(characterDto.getValues().value(currentNation).toStdString())
                .setStatus(toStatus(characterDto.getValues().value(status)))
                .setDescription(characterDto.getValues().value(description).toStdString())
                .setRoles(toRoles(characterDto.getRoles()))
//                .setSkills(toSkills(characterDto.getSkills()))
//                .setRelationships(toRelationships(characterDto.getRelationships()))
//                .setEthnies(toEthnies(characterDto.getEthnies()))
                .setGroups(toGroups(characterDto.getGroups()))
//                .setMiniAvatar(characterDto.getAvatars())
//                .setAvatars(toAvatars(characterDto.getAvatars()))
                ;

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
        throw std::runtime_error("Not implemented");
    }

    QVector<AvatarDto> CharacterAdapter::toAvatarDtos(std::vector<std::string> avatars)
    {
        throw std::runtime_error("Not implemented");
    }

    Core::GroupInfo CharacterAdapter::toGroup(GroupDto groupDto)
    {
        Core::GroupInfo groupInfo;
        const auto& values = groupDto.getValues();
        if (values.contains(group))
            groupInfo.setName(values[group].toString().toStdString());
        if (values.contains(type))
            groupInfo.setType(toGroupType(values[type].toString()));
        if (values.contains(subgroup))
            groupInfo.setSubgroupName(values[subgroup].toString().toStdString());
        if (values.contains(role))
            groupInfo.setRole(values[role].toString().toStdString());
        if (values.contains(isOld))
            groupInfo.setIsOld(QVariant(values[isOld]).toBool());

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
        if (typeDto == ethnieKey)
            return Core::GroupType::Ethnie;
        if (typeDto == familyKey)
            return Core::GroupType::Family;
        if (typeDto == organizationKey)
            return Core::GroupType::Organization;
        if (typeDto == guildKey)
            return Core::GroupType::Guild;
        if (typeDto == groupKey)
            return Core::GroupType::Group;

        throw std::runtime_error("Unsupported GroupType " + typeDto.toStdString());
    }

    QString CharacterAdapter::toGroupTypeDto(const Core::GroupType& type)
    {
        throw std::runtime_error("Not implemented");
    }

    Core::GroupInfo CharacterAdapter::toEthnie(QString ethnieDto)
    {
        throw std::runtime_error("Not implemented");
    }

    QString CharacterAdapter::toEthnieDto(const Core::GroupInfo& ethnie)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<Core::GroupInfo> CharacterAdapter::toEthnies(const QVector<QString>& ethnieDtos)
    {
        throw std::runtime_error("Not implemented");
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
        if (statusDto == "alive")
            return Core::Status::Alive;
        if (statusDto == "dead")
            return Core::Status::Dead;
        if (statusDto == "missing")
            return Core::Status::Missing;
        if (statusDto == "sealed")
            return Core::Status::Sealed;

        std::string errorMessage("Cannot convert status. Unknown value: " + status.toStdString());
        std::cout << errorMessage << std::endl;
        throw std::logic_error(errorMessage.c_str());
    }

    QString CharacterAdapter::toStatusDto(const Core::Status& status)
    {
        throw std::runtime_error("Not implemented");
    }
}
