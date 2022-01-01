#pragma once

#include <QString>

#include "../character/relationship.h"
#include "../character/status.h"
#include "../group/group_type.h"
#include "../homeView/home_element_type.h"

namespace Ityl::DataModel::Converters
{
    QString convertRelationshipSingularForm(const Relationship& relationship);
    QString convertRelationshipPluralForm(const Relationship& relationship);
    Relationship convertRelationshipToEnum(const QString& relationship);

    QString convertStatus(const Status& status);
    Status convertStatus(const QString& status);

    HomeElementType convertElementType(const QString& type);
    QString convertElementType(const HomeElementType& type);

    GroupType convertGroupType(const QString& type);
    QString convertGroupType(const GroupType& type);
}