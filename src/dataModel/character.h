#pragma once

#include <QMap>
#include <QString>
#include <QVector>

#include "skill/skill.h"
#include "relationship.h"

class Character
{
public:
    Character();

    Character(
        const QString& firstName,
        const QString& lastName,
        const QString& nickName,
        const QString& title,
        const QString& quote,
        const QString& avatar,
        const QString& birthPlace,
        const QString& livelyPlace,
        QVector<QString>&& roles,
        QMap<QString, QList<Skill>>&& skills,
        QVector<QString>&& ethnies,
        QVector<QString>&& groups);

    QString getFirstName()const  { return _firstName; }
    QString getLastName() const { return _lastName; }
    QString getNickName() const { return _nickName; }
    QString getTitle() const { return _title; }
    QString getQuote() const { return _quote; }
    QString getAvatar() const { return _avatar; }
    QString getBirthPlace() const { return _birthPlace; }
    QString getLivelyPlace() const { return _livelyPlace; }

    QVector<QString> getRoles() const { return _roles; }
    QMap<QString, QList<Skill>> getSkills() const { return _skills; }
    QMap<Relationship, QList<QPair<QString, QString>>> getRelationships() const { return _relationships; }
    QVector<QString> getEthnies() const { return _ethnies; }
    QVector<QString> getGroups() const { return _groups; }

    QString getDescription() const { return _description; }

    void setFirstName(const QString& firstName) { _firstName = firstName; }
    void setLastName(const QString& lastName) { _lastName = lastName; }
    void setNickName(const QString& nickName) { _nickName = nickName; }
    void setTitle(const QString& title) { _title = title; }
    void setQuote(const QString& quote) { _quote = quote; }
    void setAvatar(const QString& avatar) { _avatar = avatar; }
    void setBirthPlace(const QString& birthPlace) { _birthPlace = birthPlace; }
    void setLivelyPlace(const QString& livelyPlace) { _livelyPlace = livelyPlace; }

    void setRoles(const QVector<QString>& roles) { _roles = roles; }
    void setRoles(QVector<QString>&& roles) { _roles = std::move(roles); }
    void setSkills(const QMap<QString, QList<Skill>>& skills) { _skills = skills; }
    void setSkills(QMap<QString, QList<Skill>>&& skills) { _skills = std::move(skills); }
    void setEthnies(const QVector<QString>& ethnies) { _ethnies = ethnies; }
    void setEthnies(QVector<QString>&& ethnies) { _ethnies = std::move(ethnies); }
    void setGroups(const QVector<QString>& groups) { _groups = groups; }
    void setGroups(QVector<QString>&& groups) { _groups = std::move(groups); }

    void setDescription(const QString& description) { _description = description; }
    void setDescription(QString&& description) { _description = std::move(description); }

    void addRelationship(const Relationship& relationType, QPair<QString, QString> character);
    void addRelationships(const Relationship& relationType, QList<QPair<QString, QString>> characters);

private:
    QString _firstName;
    QString _lastName;
    QString _nickName;
    QString _title;
    QString _quote;
    QString _avatar;
    QString _birthPlace;
    QString _livelyPlace;

    QVector<QString> _roles;
    QMap<QString, QList<Skill>> _skills;
    QMap<Relationship, QList<QPair<QString, QString>>> _relationships;
    QVector<QString> _ethnies;
    QVector<QString> _groups;

    QString _description;
};
