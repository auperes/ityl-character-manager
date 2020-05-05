#include "converters.h"

#include <exception>
#include <iostream>

namespace Ityl::DataModel::Converters
{
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

    UiModel::FilteringType Converters::convertFilteringType(const QString &type)
    {
        if (type == "Tous")
            return UiModel::FilteringType::None;
        if (type == QString("group"))
            return UiModel::FilteringType::Group;
        if (type == QString("ethnie"))
            return UiModel::FilteringType::Ethnie;
        if (type == QString("nation"))
            return UiModel::FilteringType::Nation;

        std::string errorMessage("Cannot convert type. Unknown value: " + type.toStdString());
        std::cout << errorMessage << std::endl;
        throw std::logic_error(errorMessage.c_str());
    }

    HomeElementType Converters::convertElementType(const QString &type)
    {
        if (type == "region")
            return HomeElementType::Region;
        if (type == "organization")
            return HomeElementType::Organization;
        if (type == "family")
            return HomeElementType::Family;
        if (type == "guild")
            return HomeElementType::Guild;
        if (type == "group")
            return HomeElementType::Group;
        if (type == "background")
            return HomeElementType::Background;
        if (type == "ethnie")
            return HomeElementType::Ethnie;

        std::string errorMessage("Cannot convert type. Unknown value: " + type.toStdString());
        std::cout << errorMessage << std::endl;
        throw std::logic_error(errorMessage.c_str());
    }

    QString Converters::convertElementType(const HomeElementType &type)
    {
        switch (type)
        {
        case HomeElementType::Region:
            return "region";
        case HomeElementType::Organization:
            return "organization";
        case HomeElementType::Family:
            return "family";
        case HomeElementType::Guild:
            return "guild";
        case HomeElementType::Group:
            return "group";
        case HomeElementType::Background:
            return "background";
        case HomeElementType::Ethnie:
            return "ethnie";
        }

        return QString();
    }

    GroupType Converters::convertGroupType(const QString& type)
    {
        if (type == "ethnie")
            return GroupType::Ethnie;
        if (type == "organization")
            return GroupType::Organization;
        if (type == "family")
            return GroupType::Family;
        if (type == "guild")
            return GroupType::Guild;

        return GroupType::Group;
    }

    QString Converters::convertGroupType(const GroupType& type)
    {
        switch (type)
        {
        case GroupType::Group:
            return "group";
        case GroupType::Ethnie:
            return "ethnie";
        case GroupType::Organization:
            return "organization";
        case GroupType::Family:
            return "family";
        case GroupType::Guild:
            return "guild";
        }

        return QString();
    }
}
