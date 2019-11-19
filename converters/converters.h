#pragma once

#include <QString>

#include "../dataModel/relationship.h"
#include "../dataModel/status.h"

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
};
