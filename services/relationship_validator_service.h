#pragma once

#include <unordered_map>
#include <set>

#include <QPair>
#include <QString>

#include "../dataModel/character/relationship.h"

namespace Ityl::Services
{
    class RelationshipValidatorService
    {
    public:
        explicit RelationshipValidatorService();

        void addCharacterName(QString characterName);
        void addRelationship(QString characterName, DataModel::Relationship relationship, QString relatedCharacterName);
        void logMissingRelationships();

    private:
        std::unordered_map<std::string, std::unordered_multimap<std::string, DataModel::Relationship>> _missingRelationships;
        std::unordered_map<DataModel::Relationship, DataModel::Relationship> _relatedRelationships;
        std::set<QString> _charactersNames;
    };
}
