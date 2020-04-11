#include "home_view.h"

namespace Ityl::DataModel
{
    HomeView::HomeView(QList<HomeCategory> &&categories)
        : _categories(std::move(categories))
    {

    }
}
