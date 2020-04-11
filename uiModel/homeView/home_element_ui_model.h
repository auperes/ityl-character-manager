#pragma once

#include <QObject>

namespace Ityl::UiModel
{
    class HomeElementUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString type READ type CONSTANT)
        Q_PROPERTY(QStringList names READ names CONSTANT)

    public:
        explicit HomeElementUiModel(QObject *parent = nullptr);
        explicit HomeElementUiModel(QString type, QList<QString> names, QObject *parent = nullptr);

        QString type() const { return _type; }
        QList<QString> names() const { return _names; }

    signals:

    private:
        QString _type;
        QList<QString> _names;
    };
}
