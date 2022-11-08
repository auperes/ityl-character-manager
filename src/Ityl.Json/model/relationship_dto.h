#pragma once

#include <QJsonObject>

namespace Ityl::Json
{
    class RelationshipDto
    {
    public:
        RelationshipDto();

        const QString& getType() const;
        void setType(const QString& type);
        const QString& getFirstName() const;
        void setFirstName(const QString& firstName);
        const QString& getLastName() const;
        void setLastName(const QString& lastName);
        bool getIsOld() const;
        void setIsOld(bool isOld);

        void read(const QJsonObject& json);
        void write(QJsonObject& json);

    private:
        QString _type;
        QString _firstName;
        QString _lastName;
        bool _isOld;
    };
}
