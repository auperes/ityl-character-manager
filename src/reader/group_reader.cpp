#include "group_reader.h"

#include <QJsonObject>

#include "../converters/converters.h"
#include "json_reader_helpers.h"

namespace Ityl::Reader
{
    DataModel::Group GroupReader::readGroupFromFile(const QString& filepath)
    {
        QJsonObject groupObject = JsonReaderHelpers::readJsonFile(filepath)["group"].toObject();
        DataModel::Group group;

        group.setName(groupObject["name"].toString());
        group.setNation(groupObject["nation"].toString());
        group.setType(DataModel::Converters::Converters::convertGroupType(groupObject["type"].toString()));
        group.setDescription(groupObject["description"].toString());
        if (groupObject.contains("parts"))
            group.setParts(readParts(groupObject["parts"].toArray()));

        return group;
    }

    QVector<DataModel::GroupPart> GroupReader::readParts(const QJsonArray& jsonParts)
    {
        QVector<DataModel::GroupPart> parts;
        parts.reserve(jsonParts.size());

        for (const auto& jsonPart : jsonParts)
            parts.push_back(readPart(jsonPart.toObject()));

        return parts;
    }

    DataModel::GroupPart GroupReader::readPart(const QJsonObject& jsonPart)
    {
        DataModel::GroupPart part;
        part.setPartName(jsonPart["name"].toString());
        part.setSubGroupName(jsonPart["subGroupName"].toString());
        part.setDescription(jsonPart["description"].toString());

        if (jsonPart.contains("parts"))
            part.setParts(readParts(jsonPart["parts"].toArray()));

        return part;
    }
}
