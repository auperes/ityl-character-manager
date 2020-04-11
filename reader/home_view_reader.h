#pragma once

#include <QString>

#include "../dataModel/homeView/home_view.h"

class HomeViewReader
{
public:
    HomeViewReader() = delete;
    ~HomeViewReader() = delete;

    static HomeView readHomeViewFromFile(const QString& filepath);
};
