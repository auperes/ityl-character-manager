#pragma once

#include "home_category.h"

namespace Ityl::DataModel
{
    class HomeView
    {
    public:
        HomeView(QList<HomeCategory>&& categories);

    private:
        QList<HomeCategory> _categories;
    };
}
