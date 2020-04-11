#pragma once

#include <QList>
#include <QMap>
#include <QString>

#include "home_element_type.h"

namespace Ityl::DataModel
{
    class HomeCategory
    {
    public:
        HomeCategory(QString name, QMap<HomeElementType, QList<QString>>&& elements);

        const QString& getName() const { return _name; }
        const QMap<HomeElementType, QList<QString>>&  getElements() const { return _elements; }

    private:
        QString _name;
        QMap<HomeElementType, QList<QString>> _elements;
    };
}
