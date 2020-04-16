#include "home_view_reader.h"

#include "../converters/converters.h"
#include "json_reader_helpers.h"

namespace Ityl::Reader
{
    DataModel::HomeView HomeViewReader::readHomeViewFromFile(const QString &filepath)
    {
        QJsonObject jsonObject = JsonReaderHelpers::readJsonFile(filepath);
        QJsonObject homeViewObject = jsonObject.value("homeView").toObject();

        DataModel::HomeView homeView(readCategories(homeViewObject["categories"].toArray()));
        return homeView;
    }

    QList<DataModel::HomeCategory> HomeViewReader::readCategories(const QJsonArray &jsonCategories)
    {
        QList<DataModel::HomeCategory> categories;

        for (auto category : jsonCategories)
            categories.push_back(readCategory(category.toObject()));

        return categories;
    }

    DataModel::HomeCategory HomeViewReader::readCategory(const QJsonObject &jsonCategory)
    {
        QString name = jsonCategory["name"].toString();
        auto elements = readElements(jsonCategory["elements"].toArray());

        return DataModel::HomeCategory(name, std::move(elements));
    }

    QMap<DataModel::HomeElementType, QList<QString> > HomeViewReader::readElements(const QJsonArray &jsonElements)
    {
        QMap<DataModel::HomeElementType, QList<QString> > elements;

        for (auto element : jsonElements)
        {
            QJsonObject object = element.toObject();
            QString type = object["type"].toString();
            QString name = object["name"].toString();
            DataModel::HomeElementType elementType = DataModel::Converters::Converters::convertElementType(type);
            if (elements.contains(elementType))
                elements[elementType].push_back(name);
            else
                elements.insert(elementType, QList<QString> { name });
        }
        return elements;
    }
}
