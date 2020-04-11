#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include "home_element_ui_model.h"

namespace Ityl::UiModel
{
    class HomeCategoryUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QAbstractItemModel* elements READ elements CONSTANT)

    public:
        explicit HomeCategoryUiModel(QObject *parent = nullptr);

        QAbstractItemModel* elements() const { return _elements; }

    signals:

    private:
        QAbstractItemModel* _elements;
        QList<std::shared_ptr<HomeElementUiModel>> _elementUiModels;
    };
}
