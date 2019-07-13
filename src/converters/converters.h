#pragma once

#include <QString>

#include "../dataModel/relationship.h"

class Converters
{
public:
    Converters() = delete;
    ~Converters() = delete;

    static QString convertRelationshipSingularForm(const Relationship& relationship);
    static QString convertRelationshipPluralForm(const Relationship& relationship);
    static Relationship convertRelationshipToEnum(const QString& relationship);
};
