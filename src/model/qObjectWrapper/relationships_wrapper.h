#pragma once

#include <QObject>
#include <QMap>

#include "../../dataModel/relationship.h"

class RelationshipsWrapper : public QObject
{
    Q_OBJECT
public:
    explicit RelationshipsWrapper(QObject *parent = nullptr);
    RelationshipsWrapper(const QMap<Relationship, QList<QPair<QString, QString>>> &relationships, QObject *parent = nullptr);
    explicit RelationshipsWrapper(const RelationshipsWrapper &relationshipsWrapper);

    QMap<Relationship, QList<QPair<QString, QString>>> relationships() const;

signals:

public slots:

private:
    QMap<Relationship, QList<QPair<QString, QString>>> _relationships;
};
