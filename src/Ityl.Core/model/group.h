#pragma once

#include <string>
#include <vector>

#include "group_part.h"
#include "group_type.h"

namespace Ityl::Core
{
    class Group
    {
    public:
        static const std::string RootPartName;
        static const std::string RootSubgroup;

        Group() = default;
        Group(const std::string& name, const std::string& nation, const GroupType& type, const std::string& description);

        const std::string& getName() const { return _name; }
        const std::string& getNation() const { return _nation; }
        const GroupType& getType() const { return _type; }
        const std::string& getDescription() const { return _description; }
        const std::vector<std::shared_ptr<GroupPart>>& getParts() const { return _parts; }

        void setName(const std::string& name) { _name = name; }
        void setNation(const std::string& nation) { _nation = nation; }
        void setType(const GroupType& type) { _type = type; }
        void setDescription(const std::string& description) { _description = description; }
        void setParts(const std::vector<std::shared_ptr<GroupPart>>& parts) { _parts = parts; }

        void addPart(const std::shared_ptr<GroupPart>& part) { _parts.push_back(part); }

    private:
        std::string _name;
        std::string _nation;
        GroupType _type;
        std::string _description;

        std::vector<std::shared_ptr<GroupPart>> _parts;
    };
}
