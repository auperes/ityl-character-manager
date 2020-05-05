#pragma once

#include <QString>
#include <QVector>

#include "group_part.h"
#include "group_type.h"

namespace Ityl::DataModel
{
    class Group
    {
    public:
        Group();

        QString getName() const { return _name; }
        QString getNation() const { return _nation; }
        GroupType getType() const { return _type; }
        QString getDescription() const { return _description; }
        QVector<GroupPart> getParts() const { return _parts; }

        void setName(const QString& name) { _name = name; }
        void setNation(const QString& nation) { _nation = nation; }
        void setType(const GroupType& type) { _type = type; }
        void setDescription(const QString& description) { _description = description; }
        void setParts(const QVector<GroupPart>& parts) { _parts = parts; }

    private:
        QString _name;
        QString _nation;
        GroupType _type;
        QString _description;

        QVector<GroupPart> _parts;
    };
}
