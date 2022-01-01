#include "relationship_ui_model.h"

#include <converters/data_model_converters.h>

namespace Ityl::Ui::UiModels
{
    RelationshipUiModel::RelationshipUiModel(QObject *parent) : QObject(parent)
    {

    }

    RelationshipUiModel::RelationshipUiModel(const DataModel::Relationship &relationship, const QList<QPair<QString, QString> > &names, QObject *parent)
        : QObject (parent)
        , _relationshipType(relationship)
        , _relationshipNames(names)
    {
        _type  = _relationshipNames.size() > 1
                ? DataModel::Converters::convertRelationshipPluralForm(_relationshipType)
                : DataModel::Converters::convertRelationshipSingularForm(_relationshipType);

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
}
