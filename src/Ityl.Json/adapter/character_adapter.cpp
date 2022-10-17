#include "character_adapter.h"

#include <iostream>
#include <string>
#include <QString>

namespace Ityl::Json
{
    const QString firstName = "firstName";
    const QString lastName = "lastName";
    const QString birthName = "birthName";
    const QString nickName = "nickName";
    const QString title = "title";
    const QString quote = "quote";
    const QString birthPlace = "birthPlace";
    const QString livelyPlace = "livelyPlace";
    const QString birthNation = "birthNation";
    const QString currentNation = "currentNation";
    const QString birthDate = "birthDate";
    const QString deathDate = "deathDate";
    const QString status = "status";
    const QString description = "description";

    Core::Character CharacterAdapter::toCharacter(const CharacterDto& characterDto)
    {
        Core::Character character;
        character
                .setFirstName(characterDto.getValues().value(firstName).toStdString())
                .setLastName(characterDto.getValues().value(lastName).toStdString())
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
//                .setGroups(toGroups(characterDto.getGroups()))
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
        throw std::runtime_error("Not implemented");
    }

    GroupDto CharacterAdapter::toGroupDto(const Core::GroupInfo& group)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<Core::GroupInfo> CharacterAdapter::toGroups(const QVector<GroupDto>& groupDtos)
    {
        throw std::runtime_error("Not implemented");
    }

    QVector<GroupDto> CharacterAdapter::toGroupDtos(const std::vector<Core::GroupInfo>& groups)
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
        throw std::runtime_error("Not implemented");
    }

    QString CharacterAdapter::toRoleDto(const std::string& role)
    {
        throw std::runtime_error("Not implemented");
    }

    std::vector<std::string> CharacterAdapter::toRoles(const QVector<QString>& roleDtos)
    {
        std::vector<std::string> roles;
        roles.reserve(roleDtos.size());

        for (const auto& role : roleDtos)
            roles.push_back(role.toStdString());

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
