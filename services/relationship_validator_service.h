#pragma once

#include <map>
#include <unordered_map>
#include <set>

#include <QPair>
#include <QString>

#include "../dataModel/relationship.h"

class RelationshipValidatorService
{
public:
    explicit RelationshipValidatorService();

    void addCharacterName(QString characterName);
    void addRelationship(QString characterName, Relationship relationship, QString relatedCharacterName);
    void logMissingRelationships();

//    std::unordered_map<QPair<QString, QString>, std::map<QPair<QString, QString>, Relationship>> missingRelationships() const { return _missingRelationships; }

private:
    std::map<QString, std::map<QString, Relationship>> _missingRelationships;
    std::unordered_map<Relationship, Relationship> _relatedRelationships;
    std::set<QString> _charactersNames;
};

