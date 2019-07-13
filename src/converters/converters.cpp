#include "converters.h"

#include <exception>

QString Converters::convertRelationshipSingularForm(const Relationship& relationship)
{
    QString value;
    switch (relationship)
    {
    case Aunt:
        value = "Tante";
        break;
    case Wife:
        value = "Femme";
        break;
    case Child:
        value = "Enfant";
        break;
    case Uncle:
        value = "Oncle";
        break;
    case Cousin:
        value = "Cousin";
        break;
    case Father:
        value = "Père";
        break;
    case Mother:
        value = "Mère";
        break;
    case Nephew:
        value = "Neveu";
        break;
    case Husband:
        value = "Mari";
        break;
    case Sibling:
        value = "Adelphe";
        break;
    case Grandchild:
        value = "Petit-enfant";
        break;
    case Grandfather:
        value = "Grand-père";
        break;
    case Grandmother:
        value = "Grand-mère";
        break;
    case HalfSibling:
        value = "Demi-adelphe";
        break;
    };
    return value;
}

QString Converters::convertRelationshipPluralForm(const Relationship& relationship)
{
    QString value;
    switch (relationship)
    {
    case Aunt:
        value = "Tantes";
        break;
    case Wife:
        value = "Femmes";
        break;
    case Child:
        value = "Enfants";
        break;
    case Uncle:
        value = "Oncles";
        break;
    case Cousin:
        value = "Cousins";
        break;
    case Father:
        value = "Pères";
        break;
    case Mother:
        value = "Mères";
        break;
    case Nephew:
        value = "Neveux";
        break;
    case Husband:
        value = "Maris";
        break;
    case Sibling:
        value = "Adelphes";
        break;
    case Grandchild:
        value = "Petits-enfants";
        break;
    case Grandfather:
        value = "Grands-pères";
        break;
    case Grandmother:
        value = "Grands-mères";
        break;
    case HalfSibling:
        value = "Demi-adelphes";
        break;
    };
    return value;
}

Relationship Converters::convertRelationshipToEnum(const QString& relationship)
{
    if (relationship == "aunt")
        return Relationship::Aunt;
    if (relationship == "wife")
        return Relationship::Wife;
    if (relationship == "child")
        return Relationship::Child;
    if (relationship == "uncle")
        return Relationship::Uncle;
    if (relationship == "cousin")
        return Relationship::Cousin;
    if (relationship == "father")
        return Relationship::Father;
    if (relationship == "mother")
        return Relationship::Mother;
    if (relationship == "nephew")
        return Relationship::Nephew;
    if (relationship == "husband")
        return Relationship::Husband;
    if (relationship == "sibling")
        return Relationship::Sibling;
    if (relationship == "grandchild")
        return Relationship::Grandchild;
    if (relationship == "grandfather")
        return Relationship::Grandfather;
    if (relationship == "grandmother")
        return Relationship::Grandmother;
    if (relationship == "halfsibling")
        return Relationship::HalfSibling;
    throw std::exception();
}
