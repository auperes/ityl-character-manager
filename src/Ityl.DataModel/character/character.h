#pragma once

#include <QMap>
#include <QString>
#include <QVector>

#include "skill/skill.h"
#include "status.h"
#include "relationship.h"
#include "../group/group_info.h"

namespace Ityl::DataModel
{
    class Character
    {
    public:
        Character();

        const QString& getFirstName()const  { return _firstName; }
        const QString& getLastName() const { return _lastName; }
        const QString getBirthName() const {return _birthName; }
        const QString& getNickName() const { return _nickName; }
        const QString& getTitle() const { return _title; }
        const QString& getQuote() const { return _quote; }
        const QString& getBirthPlace() const { return _birthPlace; }
        const QString& getLivelyPlace() const { return _livelyPlace; }
        const QString getBirthNation() const { return _birthNation; }
        const QString getCurrentNation() const { return _currentNation; }
        Status getStatus() const { return _status; }

        QVector<QString> getRoles() const { return _roles; }
        QMap<QString, QList<Skill>> getSkills() const { return _skills; }
        QMap<Relationship, QList<QPair<QString, QString>>> getRelationships() const { return _relationships; }
        const QVector<GroupInfo>& getEthnies() const { return _ethnies; }
        const QVector<GroupInfo>& getGroups() const { return _groups; }
        const QVector<QString>& getAvatars() const { return _avatars; }

        const QString& getDescription() const { return _description; }

        void setFirstName(const QString& firstName) { _firstName = firstName; }
        void setLastName(const QString& lastName) { _lastName = lastName; }
        void setBirthName(const QString &birthName) { _birthName = birthName; }
        void setNickName(const QString& nickName) { _nickName = nickName; }
        void setTitle(const QString& title) { _title = title; }
        void setQuote(const QString& quote) { _quote = quote; }
        void setBirthPlace(const QString& birthPlace) { _birthPlace = birthPlace; }
        void setLivelyPlace(const QString& livelyPlace) { _livelyPlace = livelyPlace; }
        void setBirthNation(const QString &birthNation) { _birthNation = birthNation; }
        void setCurrentNation(const QString &currentNation) { _currentNation = currentNation; }
        void setStatus(const Status &status) { _status = status; }

        void setRoles(const QVector<QString>& roles) { _roles = roles; }
        void setRoles(QVector<QString>&& roles) { _roles = std::move(roles); }
        void setSkills(const QMap<QString, QList<Skill>>& skills) { _skills = skills; }
        void setSkills(QMap<QString, QList<Skill>>&& skills) { _skills = std::move(skills); }
        void setEthnies(const QVector<GroupInfo>& ethnies) { _ethnies = ethnies; }
        void setEthnies(QVector<GroupInfo>&& ethnies) { _ethnies = std::move(ethnies); }
        void setGroups(const QVector<GroupInfo>& groups) { _groups = groups; }
        void setGroups(QVector<GroupInfo>&& groups) { _groups = std::move(groups); }
        void setAvatars(const QVector<QString> &avatars) { _avatars = avatars; }
        void setAvatars(QVector<QString> &&avatars) { _avatars = std::move(avatars); }

        void setDescription(const QString& description) { _description = description; }
        void setDescription(QString&& description) { _description = std::move(description); }

        void addRelationship(const Relationship& relationType, QPair<QString, QString> character);
        void addRelationships(const Relationship& relationType, QList<QPair<QString, QString>> characters);

    private:
        QString _firstName;
        QString _lastName;
        QString _birthName;
        QString _nickName;
        QString _title;
        QString _quote;
        QString _birthPlace;
        QString _livelyPlace;
        QString _birthNation;
        QString _currentNation;
        Status _status;

        QVector<QString> _roles;
        QMap<QString, QList<Skill>> _skills;
        QMap<Relationship, QList<QPair<QString, QString>>> _relationships;
        QVector<GroupInfo> _ethnies;
        QVector<GroupInfo> _groups;
        QVector<QString> _avatars;

        QString _description;
    };
}
