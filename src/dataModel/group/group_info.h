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
        GroupInfo(const QString& name, const QString& subGroupName, const GroupType& type, bool isOld);

        QString getName() const { return _name; }
        QString getSubGroupName() const { return _subGroupName; }
        GroupType getType() const { return _type; }
        bool getIsOld() const { return _isOld; }

        void setName(const QString& name) { _name = name; }
        void setSubGroupName(const QString& subGroupName) { _subGroupName = subGroupName; }
        void setType(const GroupType& type) { _type = type; }
        void setIsOld(bool isOld) { _isOld = isOld; }

    private:
        QString _name;
        QString _subGroupName;
        GroupType _type;
        bool _isOld;
    };
}

