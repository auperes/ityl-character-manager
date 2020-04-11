#pragma once

#include <QList>
#include <QMap>
#include <QObject>
#include <QString>

#include "home_category_ui_model.h"

namespace Ityl::UiModel
{
    class HomeViewUIModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QStringList categoriesNames READ categoriesNames CONSTANT)

    public:
        explicit HomeViewUIModel(QObject *parent = nullptr); //TODO get home view data model and convert it to ui model

        QList<QString> categoriesNames() const { return _categoriesNames; }

        Q_INVOKABLE HomeCategoryUiModel* getCategory(const QString& categoryName) const; //TODO implement me

    signals:

    private:
        QList<QString> _categoriesNames;
        QMap<QString, std::shared_ptr<HomeCategoryUiModel>> _categoriesByName;
    };
}
