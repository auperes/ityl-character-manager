#include "converters.h"

#include <exception>
#include <iostream>

QString Converters::convertRelationshipSingularForm(const Relationship& relationship)
{
    QString value;
    switch (relationship)
    {
    case UncleAunt:
        value = "Oncle/Tante";
        break;
    case Wife:
        value = "Femme";
        break;
    case Child:
        value = "Enfant";
        break;
    case Cousin:
        value = "Cousin";
        break;
    case Parent:
        value = "Parent";
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
    case GrandChild:
        value = "Petit-enfant";
        break;
    case GrandParent:
        value = "Grand-parent";
        break;
    case HalfSibling:
        value = "Demi-adelphe";
        break;
    case Guardian:
        value = "Gardien";
        break;
    case Partner:
        value ="Partenaire";
        break;
    case Twin:
        value = "Jumeau";
        break;
    case Protege:
        value = "Protégé";
        break;
    case Betrothed:
        value = "Fiancé(e)";
        break;
    case Master:
        value = "Maître";
        break;
    case AdoptiveSibling:
        value = "Adelphe adoptif";
        break;
    case Disciple:
        value = "Disciple";
        break;
    case RightHand:
        value = "Bras droit";
        break;
    case RightHandOf:
        value = "Bras droit de";
        break;
    case Rival:
        value = "Rival";
        break;
    }
    return value;
}

QString Converters::convertRelationshipPluralForm(const Relationship& relationship)
{
    QString value;
    switch (relationship)
    {
    case UncleAunt:
        value = "Oncles/Tantes";
        break;
    case Wife:
        value = "Femmes";
        break;
    case Child:
        value = "Enfants";
        break;
    case Cousin:
        value = "Cousins";
        break;
    case Parent:
        value = "Parents";
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
    case GrandChild:
        value = "Petits-enfants";
        break;
    case GrandParent:
        value = "Grands-parents";
        break;
    case HalfSibling:
        value = "Demi-adelphes";
        break;
    case Guardian:
        value = "Gardiens";
        break;
    case Partner:
        value = "Partenaires";
        break;
    case Twin:
        value = "Jumeaux";
        break;
    case Protege:
        value = "Protégés";
        break;
    case Betrothed:
        value = "Fiancés";
        break;
    case Master:
        value = "Maîtres";
        break;
    case AdoptiveSibling:
        value = "Adelphes adoptifs";
        break;
    case Disciple:
        value = "Disciples";
        break;
    case RightHand:
        value = "Bras droits";
        break;
    case RightHandOf:
        value = "Bras droit de";
        break;
    case Rival:
        value = "Rivaux";
        break;
    }
    return value;
}

Relationship Converters::convertRelationshipToEnum(const QString& relationship)
{
    if (relationship == "uncleAunt")
        return Relationship::UncleAunt;
    if (relationship == "wife")
        return Relationship::Wife;
    if (relationship == "child")
        return Relationship::Child;
    if (relationship == "cousin")
        return Relationship::Cousin;
    if (relationship == "parent")
        return Relationship::Parent;
    if (relationship == "nephew")
        return Relationship::Nephew;
    if (relationship == "husband")
        return Relationship::Husband;
    if (relationship == "sibling")
        return Relationship::Sibling;
    if (relationship == "grandChild")
        return Relationship::GrandChild;
    if (relationship == "grandParent")
        return Relationship::GrandParent;
    if (relationship == "halfSibling")
        return Relationship::HalfSibling;
    if (relationship == "guardian")
        return Relationship::Guardian;
    if (relationship == "partner")
        return Relationship::Partner;
    if (relationship == "twin")
        return Relationship::Twin;
    if (relationship == "protege")
        return Relationship::Protege;
    if (relationship == "betrothed")
        return Relationship::Betrothed;
    if (relationship == "master")
        return Relationship::Master;
    if (relationship == "adoptiveSibling")
        return Relationship::AdoptiveSibling;
    if (relationship == "disciple")
        return Relationship::Disciple;
    if (relationship == "rightHand")
        return Relationship::RightHand;
    if (relationship == "rightHandOf")
        return Relationship::RightHandOf;
    if (relationship == "rival")
        return Relationship::Rival;

    std::string errorMessage("Cannot convert relationship name. Unknown value: " + relationship.toStdString());
    std::cout << errorMessage << std::endl;
    throw std::logic_error(errorMessage.c_str());
}

QString Converters::convertStatus(const Status &status)
{
    QString value;

    switch (status) {
    case Dead:
        value = "mort";
        break;
    case Alive:
        value = "vivant";
        break;
    case Sealed:
        value = "scellé";
        break;
    case Missing:
        value = "disparu";
        break;
    }

    return value;
}

Status Converters::convertStatus(const QString &status)
{
    if (status == "dead")
        return Status::Dead;
    if (status == "alive")
        return Status::Alive;
    if (status == "sealed")
        return Status::Sealed;
    if (status == "missing")
        return Status::Missing;

    std::string errorMessage("Cannot convert status. Unknown value: " + status.toStdString());
    std::cout << errorMessage << std::endl;
    throw std::logic_error(errorMessage.c_str());
}

QString Converters::convertNationToColor(const QString &nation)
{
    if (nation == "Askash")
        return "#f9d6bb";
    if (nation == "Hystiam")
        return "#ecc4c4";
    if (nation == "Oskah")
        return "#b3cff1";
    if (nation == "Saïni")
        return "#d3bbda";
    if (nation == "Zherkum")
        return "#cae6bf";

    std::string errorMessage("Cannot convert nation. Unknown value: " + nation.toStdString());
    std::cout << errorMessage << std::endl;
    return "#000000";
//    throw std::logic_error(errorMessage.c_str());
}
