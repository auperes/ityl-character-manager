#include "home_element_ui_model.h"

namespace Ityl::UiModel
{
    HomeElementUiModel::HomeElementUiModel(QObject *parent)
        : QObject(parent)
        , _type(QString())
    {

    }

    HomeElementUiModel::HomeElementUiModel(QString type, QList<QString> names, QObject *parent)
        : QObject(parent)
        , _type(type)
        , _names(names)
    {

    }
}
