#pragma once

#include <QString>

#include "../dataModel/character/relationship.h"
#include "../dataModel/character/status.h"
#include "../uiModel/filtering_type.h"

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

        static QString convertNationToColor(const QString& nation);

        static UiModel::FilteringType convertFilteringType(const QString& type);
    };
}
