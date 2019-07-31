#include "relationship_model.h"

#include "../converters/converters.h"

RelationshipModel::RelationshipModel(QObject *parent)
    : QAbstractListModel(parent)
    , _relationshipsWrapper(nullptr)
{
}

int RelationshipModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _relationshipsWrapper->relationships().size();
}

QVariant RelationshipModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Relationship relationship = _relationshipsWrapper->relationships().keys().at(index.row());
    const QList<QPair<QString, QString>> relationshipNames = _relationshipsWrapper->relationships().value(relationship);

    switch (role) {
    case RelationshipTypeRole:
    {
        if (relationshipNames.size() > 1)
            return QVariant(Converters::convertRelationshipPluralForm(relationship));
        return QVariant(Converters::convertRelationshipSingularForm(relationship));
    }
    case RelationshipNamesRole:
    {

        QString relationshipsDetail("");
        for (auto it  = relationshipNames.begin(); it != relationshipNames.end(); ++it)
        {
            auto relationship = *it;
            relationshipsDetail += relationship.first + " " + relationship.second;

            if (it+1 != relationshipNames.end())
            {
                relationshipsDetail += ", ";
            }
        }
        return QVariant(relationshipsDetail);
    }
    }

    return QVariant();
}

QHash<int, QByteArray> RelationshipModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[RelationshipTypeRole] = "type";
    names[RelationshipNamesRole] = "names";
    return names;
}

std::shared_ptr<RelationshipsWrapper> RelationshipModel::relationshipsWrapper() const
{
    return _relationshipsWrapper;
}

void RelationshipModel::setRelationshipsWrapper(std::shared_ptr<RelationshipsWrapper> relationshipsWrapper)
{
    beginResetModel();

    if (_relationshipsWrapper)
        relationshipsWrapper->disconnect(this);

    _relationshipsWrapper = relationshipsWrapper;

    endResetModel();
}
