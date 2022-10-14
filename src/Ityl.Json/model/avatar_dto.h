#pragma once

#include <QJsonObject>

namespace Ityl::Json
{
    class AvatarDto
    {
    public:
        AvatarDto();

        void read(const QJsonObject& json);
        void write(QJsonObject& json);
    };
}
