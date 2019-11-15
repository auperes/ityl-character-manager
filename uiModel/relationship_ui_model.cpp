#include "relationship_ui_model.h"

#include "../converters/converters.h"

RelationshipUiModel::RelationshipUiModel(QObject *parent) : QObject(parent)
{

}

RelationshipUiModel::RelationshipUiModel(const Relationship &relationship, const QList<QPair<QString, QString> > &names, QObject *parent)
    : QObject (parent)
    , _relationshipType(relationship)
    , _relationshipNames(names)
{
    _type  = _relationshipNames.size() > 1
            ? Converters::convertRelationshipPluralForm(_relationshipType)
            : Converters::convertRelationshipSingularForm(_relationshipType);

    _names = createRelationDetails(_relationshipNames);
}

QString RelationshipUiModel::createRelationDetails(const QList<QPair<QString, QString> > &names) const
{
    QString relationshipsDetail("");
    for (auto it  = names.begin(); it != names.end(); ++it)
    {
        auto relationship = *it;
        relationshipsDetail += relationship.first + " " + relationship.second;

        if (it+1 != names.end())
        {
            relationshipsDetail += ", ";
        }
    }
    return relationshipsDetail;
}

