#include "character.h"

Character::Character() {}

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
