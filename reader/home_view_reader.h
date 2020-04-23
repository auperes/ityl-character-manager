#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include <QMap>
#include <QString>

#include "../dataModel/homeView/home_category.h"
#include "../dataModel/homeView/home_view.h"

namespace Ityl::Reader
{
    class HomeViewReader
    {
    public:
        HomeViewReader() = delete;
        ~HomeViewReader() = delete;

        static DataModel::HomeView readHomeViewFromFile(const QString& filepath);

    private:
        static QList<DataModel::HomeCategory> readCategories(const QJsonArray& jsonCategories);
        static DataModel::HomeCategory readCategory(const QJsonObject& jsonCategory);
        static QMap<DataModel::HomeElementType, QList<QString>> readElements(const QJsonArray& jsonElements);
        static void readEthnieElement(QMap<DataModel::HomeElementType, QList<QString>>& elements, const QJsonObject& jsonRegion);

        static void insertElement(
                QMap<DataModel::HomeElementType, QList<QString>>& elements,
                const DataModel::HomeElementType& elementType,
                const QString& elementName);
    };
}
