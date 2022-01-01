#pragma once

#include <QString>

#include <character/relationship.h>
#include <character/status.h>
#include <homeView/home_element_type.h>
#include <group/group_type.h>

#include "../models/character/filtering_type.h"

namespace Ityl::DataModel::Converters
{
    class Converters
    {
    public:
        Converters() = delete;
        ~Converters() = delete;

        static QString convertRelationshipSingularForm(const Relationship& relationship);
        static QString convertRelationshipPluralForm(const Relationship& relationship);
        static Relationship convertRelationshipToEnum(const QString& relationship);

        static QString convertStatus(const Status& status);
        static Status convertStatus(const QString& status);

        static Ui::Models::FilteringType convertFilteringType(const QString& type);

        static HomeElementType convertElementType(const QString& type);
        static QString convertElementType(const HomeElementType& type);

        static GroupType convertGroupType(const QString& type);
        static QString convertGroupType(const GroupType& type);
    };
}
