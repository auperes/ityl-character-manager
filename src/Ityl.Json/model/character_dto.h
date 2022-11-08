#pragma once

#include <QJsonArray>
#include <QJsonObject>
#include <QHash>
#include <QString>
#include <QVector>

#include "avatar_dto.h"
#include "group_dto.h"
#include "relationship_dto.h"
#include "skill_dto.h"
#include "json_model_mapper.h"

namespace Ityl::Json
{
    class CharacterDto
    {
    public:
        CharacterDto() = default;

        const QHash<QString, QString>& getValues() const { return _values; }
        const QVector<QString>& getRoles() const { return _roles; }
        const QVector<SkillDto>& getSkills() const { return _skills; }
        const QVector<RelationshipDto>& getRelationships() const { return _relationships; }
        const QVector<QString>& getEthnies() const { return _ethnies; }
        const QVector<GroupDto>& getGroups() const { return _groups; }
        const QVector<AvatarDto>& getAvatars() const { return _avatars; }

        void setValues(const QHash<QString, QString>& newValues);
        void setRoles(const QVector<QString>& newRoles);
        void setSkills(const QVector<SkillDto>& newSkills);
        void setRelationships(const QVector<RelationshipDto>& newRelationships);
        void setEthnies(const QVector<QString>& newEthnies);
        void setGroups(const QVector<GroupDto>& newGroups);
        void setAvatars(const QVector<AvatarDto>& newAvatars);

        void read(const QJsonObject& json);
        void write(QJsonObject& json);

    private:
        QHash<QString, QString> _values;
        QVector<QString> _roles;
        QVector<SkillDto> _skills;
        QVector<RelationshipDto> _relationships;
        QVector<QString> _ethnies;
        QVector<GroupDto> _groups;
        QVector<AvatarDto> _avatars;

        void readValues(const QJsonArray& json);
        void readRoles(const QJsonArray& json);
        void readSkills(const QJsonArray& json);
        void readRelationships(const QJsonArray& json);
        void readEthnies(const QJsonArray& json);
        void readGroups(const QJsonArray& json);
        void readAvatars(const QJsonArray& json);
    };
}
