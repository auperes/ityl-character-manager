#pragma once

#include <QJsonObject>
#include <QString>
#include <QMap>

namespace Ityl::Reader
{
    class JsonReaderHelpers
    {
    public:
        JsonReaderHelpers() = delete;
        ~JsonReaderHelpers() = delete;

        static QJsonObject readJsonFile(const QString& filepath);

        static QMap<QString, QString> readNationsColor(const QString& filepath);
    };
}
