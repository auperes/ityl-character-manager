#pragma once

#include <QList>
#include <QMap>
#include <QObject>
#include <QString>

#include "../../dataModel/homeView/home_category.h"

namespace Ityl::UiModel
{
    class HomeViewUIModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QStringList categoriesNames READ categoriesNames CONSTANT)

    public:
        explicit HomeViewUIModel(QObject *parent = nullptr);

        QList<QString> categoriesNames() const { return _categoriesNames; }

    signals:

    private:
        QList<QString> _categoriesNames;
        QMap<QString, DataModel::HomeCategory> _categoriesByName;
    };
}
