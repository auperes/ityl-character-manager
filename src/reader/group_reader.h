#pragma once

#include <QJsonArray>

#include "../dataModel/group/group.h"

namespace Ityl::Reader
{
    class GroupReader
    {
    public:
        GroupReader() = delete;
        ~GroupReader() = delete;
        GroupReader(const GroupReader&) = delete;
        GroupReader& operator=(const GroupReader&) = delete;

        static DataModel::Group readGroupFromFile(const QString& filepath);

    private:
        static QVector<DataModel::GroupPart> readParts(const QJsonArray& jsonParts);
        static DataModel::GroupPart readPart(const QJsonObject& jsonPart);
    };
}
