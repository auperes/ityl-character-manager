#pragma once

#include <unordered_map>

#include <model/character.h>

#include "../model/character_dto.h"

namespace Ityl::Json
{
    class CharacterAdapter
    {
    public:
        Core::Character toCharacter(const CharacterDto& characterDto);
        CharacterDto toCharacterDto(const Core::Character& character);

    private:
        static const QString firstNameKey;
        static const QString lastNameKey;
        static const QString birthName;
        static const QString nickName;
        static const QString title;
        static const QString quote;
        static const QString birthPlace;
        static const QString livelyPlace;
        static const QString birthNation;
        static const QString currentNation;
        static const QString birthDate;
        static const QString deathDate;
        static const QString status;
        static const QString description;

        static const QString group;
        static const QString type;
        static const QString subgroup;
        static const QString role;
        static const QString isOld;

        static const QString ethnieKey;
        static const QString organizationKey;
        static const QString familyKey;
        static const QString guildKey;
        static const QString groupKey;

        // Avatar
        std::string toAvatar(const AvatarDto& avatarDto);
        AvatarDto toAvatarDto(const std::string& avatar);
        std::vector<std::string> toAvatars(const QVector<AvatarDto>& avatarDtos);
        QVector<AvatarDto> toAvatarDtos(std::vector<std::string> avatars);

        // Group
        Core::GroupInfo toGroup(GroupDto groupDto);
        GroupDto toGroupDto(const Core::GroupInfo& group);
        std::vector<Core::GroupInfo> toGroups(const QVector<GroupDto>& groupDtos);
        QVector<GroupDto> toGroupDtos(const std::vector<Core::GroupInfo>& groups);

        Core::GroupType toGroupType(const QString& typeDto);
        QString toGroupTypeDto (const Core::GroupType& type);

        // Ethnie
        Core::GroupInfo toEthnie(QString ethnieDto);
        QString toEthnieDto(const Core::GroupInfo& ethnie);
        std::vector<Core::GroupInfo> toEthnies(const QVector<QString>& ethnieDtos);
        QVector<QString> toEthnieDtos(const std::vector<Core::GroupInfo>& ethnies);

        // Relationship
    //    Core::GroupInfo toRelationship(GroupDto groupDto);
    //    GroupDto toRelationshipDto(const Core::GroupInfo& group);
        std::unordered_map<Core::Relationship, std::vector<std::pair<std::string, std::string>>> toRelationships(const QVector<RelationshipDto>& relationshipDtos);
        QVector<RelationshipDto> toRelationshipDtos(const std::unordered_map<Core::Relationship, std::vector<std::pair<std::string, std::string>>>& relationships);

        // Role
        std::string toRole(QString roleDto);
        QString toRoleDto(const std::string& role);
        std::vector<std::string> toRoles(const QVector<QString>& roleDtos);
        QVector<QString> toRoleDtos(const std::vector<std::string>& roles);

        // Skill
        std::vector<Core::Skill> toSkill(SkillDto skillDto);
        SkillDto toSkillDto(const std::vector<Core::Skill>& skill);
        std::unordered_map<std::string, std::vector<Core::Skill>> toSkills(const QVector<SkillDto>& skillDtos);
        QVector<SkillDto> toSkillDtos(const std::unordered_map<std::string, std::vector<Core::Skill>>& skills);

        //Status
        Core::Status toStatus(QString statusDto);
        QString toStatusDto(const Core::Status& status);
    };
}
