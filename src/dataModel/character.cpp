#include "character.h"

Character::Character() {}

Character::Character(
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
        QVector<QString>&& groups)
    : _firstName(firstName)
    , _lastName(lastName)
    , _nickName(nickName)
    , _title(title)
    , _quote(quote)
    , _avatar(avatar)
    , _birthPlace(birthPlace)
    , _livelyPlace(livelyPlace)
    , _roles(roles)
    , _skills(skills)
    , _ethnies(ethnies)
    , _groups(groups)
{
}

void Character::addRelationship(const Relationship& relationType, QPair<QString, QString> character)
{
    auto it = _relationships.find(relationType);
    if (it != _relationships.end())
        it->append(character);
    else
        _relationships.insert(relationType, QList<QPair<QString, QString>>{character});
}

void Character::addRelationships(const Relationship& relationType, QList<QPair<QString, QString>> characters)
{
    auto it = _relationships.find(relationType);
    if (it != _relationships.end())
        it->append(characters);
    else
        _relationships.insert(relationType, characters);
}
