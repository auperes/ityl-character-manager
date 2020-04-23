#pragma once

#include <QJsonObject>
#include <QString>

namespace Ityl::Reader
{
    class JsonReaderHelpers
    {
    public:
        JsonReaderHelpers() = delete;
        ~JsonReaderHelpers() = delete;

        static QJsonObject readJsonFile(const QString& filepath);
    };
}
