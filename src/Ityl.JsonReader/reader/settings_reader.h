#pragma once

#include <QJsonObject>
#include <QString>

namespace Ityl::Reader
{
    class SettingsReader
    {
    public:
        static bool readSettingsFromFile(const QString& filepath);

    private:
        static bool isSettings(const QJsonObject& settings);
    };
}
