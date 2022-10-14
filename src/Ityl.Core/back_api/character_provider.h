#pragma once

#include <string>
#include <vector>

#include "../model/character.h"

namespace Ityl::Core::Interface
{
    class CharacterProvider
    {
    public:
        virtual std::vector<Character> loadCharacters() = 0;
        virtual Character loadCharacter(const std::string& firstName, const std::string& lastName) = 0;

        virtual void saveCharacter(const Character& character) = 0;
        virtual void deleteCharacter(const std::string firstName, const std::string lastName) = 0;
    };
}
