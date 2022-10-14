#pragma once

#include <QJsonObject>

namespace Ityl::Json
{
    class GroupDto
    {
    public:
        GroupDto();

        void read(const QJsonObject& json);
        void write(QJsonObject& json);
    };
}
