#include "relationships_wrapper.h"

RelationshipsWrapper::RelationshipsWrapper(QObject *parent) : QObject(parent)
{

}

RelationshipsWrapper::RelationshipsWrapper(const QMap<Relationship, QList<QPair<QString, QString> > > &relationships, QObject *parent)
    : QObject (parent)
    , _relationships(relationships)
{

}

RelationshipsWrapper::RelationshipsWrapper(const RelationshipsWrapper &relationshipsWrapper)
    : QObject (relationshipsWrapper.parent())
    , _relationships(relationshipsWrapper.relationships())
{

}

QMap<Relationship, QList<QPair<QString, QString> > > RelationshipsWrapper::relationships() const
{
    return _relationships;
}
