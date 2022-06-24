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
        static const QString RootPartName;
        static const QString RootSubgroup;

        Group();
        Group(const QString& name, const QString& nation, const GroupType& type, const QString& description);

        const QString& getName() const { return _name; }
        const QString& getNation() const { return _nation; }
        const GroupType& getType() const { return _type; }
        const QString& getDescription() const { return _description; }
        const QVector<std::shared_ptr<GroupPart>>& getParts() const { return _parts; }

        void setName(const QString& name) { _name = name; }
        void setNation(const QString& nation) { _nation = nation; }
        void setType(const GroupType& type) { _type = type; }
        void setDescription(const QString& description) { _description = description; }
        void setParts(const QVector<std::shared_ptr<GroupPart>>& parts) { _parts = parts; }

        void addPart(const std::shared_ptr<GroupPart>& part) { _parts.push_back(part); }

    private:
        QString _name;
        QString _nation;
        GroupType _type;
        QString _description;

        QVector<std::shared_ptr<GroupPart>> _parts;
    };
}
