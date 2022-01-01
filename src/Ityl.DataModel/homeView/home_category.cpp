#include "home_category.h"

namespace Ityl::DataModel
{
    HomeCategory::HomeCategory(QString name, QMap<HomeElementType, QList<QString> > &&elements)
        : _name(name)
        , _elements(std::move(elements))
    {

    }
}
