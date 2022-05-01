#pragma once

#include <QString>

#include "group_type.h"

namespace Ityl::DataModel
{
    class GroupInfo
    {
    public:
        GroupInfo();
        GroupInfo(const QString& name);
        GroupInfo(const QString& name, const GroupType& type);
        GroupInfo(const QString& name, const QString& role, const QString& subgroupName, const GroupType& type, bool isOld);

        QString getName() const { return _name; }
        QString getRole() const { return _role; }
        QString getSubgroupName() const { return _subgroupName; }
        GroupType getType() const { return _type; }
        bool getIsOld() const { return _isOld; }

        void setName(const QString& name) { _name = name; }
        void setRole(const QString& role) { _role = role; }
        void setSubgroupName(const QString& subgroupName) { _subgroupName = subgroupName; }
        void setType(const GroupType& type) { _type = type; }
        void setIsOld(bool isOld) { _isOld = isOld; }

    private:
        QString _name;
        QString _role;
        QString _subgroupName;
        GroupType _type;
        bool _isOld;
    };
}

