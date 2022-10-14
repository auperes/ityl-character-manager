#pragma once

#include <memory>

#include "../front_api/character_api.h"
#include "../back_api/character_provider.h"

namespace Ityl::Core::Internal
{
    class CharacterService : public Interface::CharacterAPI
    {
    public:
        explicit CharacterService(std::unique_ptr<Interface::CharacterProvider> provider);

        const Character& getCharacter(const std::string& firstName, const std::string lastName);
        void addCharacter(Character&& character);
        void updateCharacter(const Character& character);
        void deleteCharacter(const std::string& firstName, const std::string& lastName);
        std::unordered_map<std::string, const Character&> getCharactersOfGroup(const std::string& groupName);
        std::vector<std::reference_wrapper<const Character>> getCharactersOfEthnie(const std::string ethnieName);

    private:
        std::unique_ptr<Interface::CharacterProvider> _provider;

        std::vector<Character> _characters;
    };
}
