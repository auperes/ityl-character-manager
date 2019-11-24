#include "converters.h"

#include <exception>
#include <iostream>

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
    case Guardian:
        value = "Gardien";
        break;
    case Partner:
        value ="Partenaire";
        break;
    case Lover:
        value = "Amant(e)";
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
    case OldWife:
        value = "Ex-femme";
        break;
    case OldHusband:
        value = "Ex-mari";
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
    case Guardian:
        value = "Gardiens";
        break;
    case Partner:
        value = "Partenaires";
        break;
    case Lover:
        value = "Amants";
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
    case OldWife:
        value = "Ex-femmes";
        break;
    case OldHusband:
        value = "Ex-maris";
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
    case Rival:
        value = "Rivaux";
        break;
    }
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
    if (relationship == "grandChild")
        return Relationship::Grandchild;
    if (relationship == "grandFather")
        return Relationship::Grandfather;
    if (relationship == "grandMother")
        return Relationship::Grandmother;
    if (relationship == "halfSibling")
        return Relationship::HalfSibling;
    if (relationship == "guardian")
        return Relationship::Guardian;
    if (relationship == "partner")
        return Relationship::Partner;
    if (relationship == "lover")
        return Relationship::Lover;
    if (relationship == "twin")
        return Relationship::Twin;
    if (relationship == "protege")
        return Relationship::Protege;
    if (relationship == "betrothed")
        return Relationship::Betrothed;
    if (relationship == "oldWife")
        return Relationship::OldWife;
    if (relationship == "oldHusband")
        return Relationship::OldHusband;
    if (relationship == "master")
        return Relationship::Master;
    if (relationship == "adoptiveSibling")
        return Relationship::AdoptiveSibling;
    if (relationship == "disciple")
        return Relationship::Disciple;
    if (relationship == "rightHand")
        return Relationship::RightHand;
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
    throw std::logic_error(errorMessage.c_str());
}
