#pragma once

#include <QJsonObject>

namespace Ityl::Json
{
    class GroupDto
    {
    public:
        GroupDto();

        const QHash<QString, QVariant>& getValues() const;

        void read(const QJsonObject& json);
        void write(QJsonObject& json);

    private:
        QHash<QString, QVariant> _values;
    };
}
