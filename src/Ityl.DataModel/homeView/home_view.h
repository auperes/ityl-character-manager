#pragma once

#include "home_category.h"

namespace Ityl::DataModel
{
    class HomeView
    {
    public:
        HomeView(QList<HomeCategory>&& categories);

        const QList<HomeCategory>& categories() const { return _categories; }

    private:
        QList<HomeCategory> _categories;
    };
}
