#include "skill.h"

namespace Ityl::Core
{
    Skill::Skill(const std::string& type)
        : _type(type)
        , _specialties(std::vector<std::string>{})
    {

    }

    Skill::Skill(const std::string& type, std::vector<std::string>&& specialties)
        : _type(type)
        , _specialties(specialties)
    {

    }
}
