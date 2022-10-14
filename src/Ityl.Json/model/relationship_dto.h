#pragma once

#include <QJsonObject>

namespace Ityl::Json
{
    class RelationshipDto
    {
    public:
        RelationshipDto();

        void read(const QJsonObject& json);
        void write(QJsonObject& json);
    };
}
