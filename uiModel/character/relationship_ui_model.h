#pragma once

#include <QObject>

#include "../../dataModel/character/relationship.h"

namespace Ityl::UiModel
{
    class RelationshipUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString type READ type CONSTANT)
        Q_PROPERTY(QString names READ names CONSTANT)

    public:
        explicit RelationshipUiModel(QObject *parent = nullptr);
        RelationshipUiModel(const DataModel::Relationship &relationship, const QList<QPair<QString, QString>> &names, QObject *parent = nullptr);

        QString type() const { return _type; }
        QString names() const { return _names; }

    signals:

    public slots:

    private:
        DataModel::Relationship _relationshipType;
        QList<QPair<QString, QString>> _relationshipNames;
        QString _type;
        QString _names;

        QString createRelationDetails(const QList<QPair<QString, QString>> &names) const;
    };
}
