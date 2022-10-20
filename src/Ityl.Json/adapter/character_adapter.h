#pragma once

#include <unordered_map>

#include <model/character.h>

#include "../model/character_dto.h"
#include "../model/json_model_mapper.h"

namespace Ityl::Json
{
    class CharacterAdapter
    {
    public:
        CharacterAdapter(std::shared_ptr<JsonModelMapper> mapper);

        Core::Character toCharacter(const CharacterDto& characterDto);
        CharacterDto toCharacterDto(const Core::Character& character);

    private:
        std::shared_ptr<JsonModelMapper> _mapper;

        // Avatar
        std::string toAvatar(const AvatarDto& avatarDto);
        AvatarDto toAvatarDto(const std::string& avatar);
        std::vector<std::string> toAvatars(const QVector<AvatarDto>& avatarDtos);
        QVector<AvatarDto> toAvatarDtos(std::vector<std::string> avatars);

        std::string toMiniAvatar(const QVector<AvatarDto>& avatarDtos);

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
