#pragma once

#include <QJsonArray>

#include <group/group.h>

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
        static QVector<std::shared_ptr<DataModel::GroupPart>> readParts(const QJsonArray& jsonParts);
        static std::shared_ptr<DataModel::GroupPart> readPart(const QJsonObject& jsonPart, QVector<std::shared_ptr<DataModel::GroupPart>>& parts, unsigned nestedLevel = 0);
    };
}
