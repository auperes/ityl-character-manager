#pragma once

#include <string>
#include <vector>

namespace Ityl::Core
{
    class Skill
    {
    public:
        Skill() = default;
        Skill(const std::string& type);
        Skill(const std::string& type, std::vector<std::string>&& specialties);

        std::string getType() const  { return _type; }
        std::vector<std::string> getSpecialties()const  { return _specialties; }

        void setType(const std::string& type) { _type = type; }
        void setSpecialties(const std::vector<std::string>& specialties) { _specialties = specialties; }
        void setSpecialties(std::vector<std::string>&& specialties) { _specialties = specialties; }

    private:
        std::string _type;
        std::vector<std::string> _specialties;
    };
}
