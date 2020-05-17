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

    QVector<std::shared_ptr<DataModel::GroupPart>> GroupReader::readParts(const QJsonArray& jsonParts)
    {
        QVector<std::shared_ptr<DataModel::GroupPart>> parts;

        for (const auto& jsonPart : jsonParts)
            readPart(jsonPart.toObject(), parts);

        return parts;
    }

    std::shared_ptr<DataModel::GroupPart> GroupReader::readPart(const QJsonObject& jsonPart, QVector<std::shared_ptr<DataModel::GroupPart>>& parts, unsigned nestedLevel)
    {
        auto part = std::make_shared<DataModel::GroupPart>();
        part->setPartName(jsonPart["name"].toString());
        part->setSubgroupName(jsonPart["subgroup"].toString());
        part->setDescription(jsonPart["description"].toString());
        part->setNestedLevel(nestedLevel);
        parts.push_back(part);

        if (jsonPart.contains("parts"))
        {
            auto jsonParts = jsonPart["parts"].toArray();

            for (const auto& jsonPart : jsonParts)
            {
                auto childPart = readPart(jsonPart.toObject(), parts, nestedLevel + 1);
                childPart->setParentPart(part);
            }
        }

        return part;
    }
}
