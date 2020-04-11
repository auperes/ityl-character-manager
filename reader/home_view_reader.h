#pragma once

#include <QString>

#include "../dataModel/homeView/home_view.h"

namespace Ityl::Reader
{
    class HomeViewReader
    {
    public:
        HomeViewReader() = delete;
        ~HomeViewReader() = delete;

        static DataModel::HomeView readHomeViewFromFile(const QString& filepath);
    };
}
