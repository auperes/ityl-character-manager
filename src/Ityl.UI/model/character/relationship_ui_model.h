#pragma once

#include <QObject>

namespace Ityl::UI
{
    class RelationshipUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString type READ type CONSTANT)
        Q_PROPERTY(QString names READ names CONSTANT)

    public:
        explicit RelationshipUiModel(QObject *parent = nullptr);

        ~RelationshipUiModel() override = default;

        QString type() const { return _type; }
        QString names() const { return _names; }

    signals:

    public slots:

    private:
        QList<QPair<QString, QString>> _relationshipNames;
        QString _type;
        QString _names;
    };
}
