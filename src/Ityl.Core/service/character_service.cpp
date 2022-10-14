#include "character_service.h"

#include <algorithm>
#include <stdexcept>

namespace Ityl::Core::Internal
{
    CharacterService::CharacterService(std::unique_ptr<Interface::CharacterProvider> provider)
        : _provider(std::move(provider))
    {
        _characters = _provider->loadCharacters();
    }

    const Character& CharacterService::getCharacter(const std::string& firstName, const std::string lastName)
    {
        auto result = std::find_if(
                    _characters.begin(),
                    _characters.end(),
                    [&firstName, &lastName](const auto& character)
        {
            return character.getFirstName() == firstName && character.getLastName() == lastName;
        });

        if (result == _characters.end())
            throw std::runtime_error("Character " + firstName + " " + lastName + " not found.");

        return *result;
    }

    void CharacterService::addCharacter(Character&& character)
    {
        throw std::runtime_error("Not implemented");
    }

    void CharacterService::updateCharacter(const Character& character)
    {
        throw std::runtime_error("Not implemented");
    }

    void CharacterService::deleteCharacter(const std::string& firstName, const std::string& lastName)
    {
        throw std::runtime_error("Not implemented");
    }

    std::unordered_map<std::string, const Character&> CharacterService::getCharactersOfGroup(const std::string& groupName)
    {
        return {};
    }

    std::vector<std::reference_wrapper<const Character>> CharacterService::getCharactersOfEthnie(const std::string ethnieName)
    {
        return {};
    }
}
