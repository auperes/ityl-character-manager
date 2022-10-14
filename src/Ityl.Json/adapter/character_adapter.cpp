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
//                .setRoles(toRoles(characterDto.getRoles()))
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

    }

    std::string CharacterAdapter::toAvatar(const AvatarDto& avatarDto)
    {

    }

    AvatarDto CharacterAdapter::toAvatarDto(const std::string& avatar)
    {

    }

    std::vector<std::string> CharacterAdapter::toAvatars(const QVector<AvatarDto>& avatarDtos)
    {

    }

    QVector<AvatarDto> CharacterAdapter::toAvatarDtos(std::vector<std::string> avatars)
    {

    }

    Core::GroupInfo CharacterAdapter::toGroup(GroupDto groupDto)
    {

    }

    GroupDto CharacterAdapter::toGroupDto(const Core::GroupInfo& group)
    {

    }

    std::vector<Core::GroupInfo> CharacterAdapter::toGroups(const QVector<GroupDto>& groupDtos)
    {

    }

    QVector<GroupDto> CharacterAdapter::toGroupDtos(const std::vector<Core::GroupInfo>& groups)
    {

    }

    Core::GroupInfo CharacterAdapter::toEthnie(QString ethnieDto)
    {

    }

    QString CharacterAdapter::toEthnieDto(const Core::GroupInfo& ethnie)
    {

    }

    std::vector<Core::GroupInfo> CharacterAdapter::toEthnies(const QVector<QString>& ethnieDtos)
    {

    }

    QVector<QString> CharacterAdapter::toEthnieDtos(const std::vector<Core::GroupInfo>& ethnies)
    {

    }

    std::unordered_map<Core::Relationship, std::vector<std::pair<std::string, std::string> > > CharacterAdapter::toRelationships(const QVector<RelationshipDto>& relationshipDtos)
    {

    }

    QVector<RelationshipDto> CharacterAdapter::toRelationshipDtos(const std::unordered_map<Core::Relationship, std::vector<std::pair<std::string, std::string> > >& relationships)
    {

    }

    std::string CharacterAdapter::toRole(QString roleDto)
    {

    }

    QString CharacterAdapter::toRoleDto(const std::string& role)
    {

    }

    std::vector<std::string> CharacterAdapter::toRoles(const QVector<QString>& roleDtos)
    {

    }

    QVector<QString> CharacterAdapter::toRoleDtos(const std::vector<std::string>& roles)
    {

    }

    std::vector<Core::Skill> CharacterAdapter::toSkill(SkillDto skillDto)
    {

    }

    SkillDto CharacterAdapter::toSkillDto(const std::vector<Core::Skill>& skill)
    {

    }

    std::unordered_map<std::string, std::vector<Core::Skill> > CharacterAdapter::toSkills(const QVector<SkillDto>& skillDtos)
    {

    }

    QVector<SkillDto> CharacterAdapter::toSkillDtos(const std::unordered_map<std::string, std::vector<Core::Skill> >& skills)
    {

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

    }
}
