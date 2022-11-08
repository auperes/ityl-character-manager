#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../model/character.h"

namespace Ityl::Core::Interface
{
    class CharacterAPI
    {
    public:
        virtual const Character& getCharacter(const std::string& firstName, const std::string lastName) = 0;
        virtual void addCharacter(Character&& character) = 0;
        virtual void updateCharacter(const Character& character) = 0;
        virtual void deleteCharacter(const std::string& firstName, const std::string& lastName) = 0;

        virtual std::unordered_map<std::string, const Character&> getCharactersOfGroup(const std::string& groupName) = 0;
        virtual std::vector<std::reference_wrapper<const Character>> getCharactersOfEthnie(const std::string ethnieName) = 0;
    };
}
