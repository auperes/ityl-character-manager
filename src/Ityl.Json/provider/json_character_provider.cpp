#include "json_character_provider.h"

#include <sstream>

namespace Ityl::Json
{

    JsonCharacterProvider::JsonCharacterProvider(JsonItemProvider<CharacterDto>&& provider, CharacterAdapter&& adapter)
        : _provider(std::move(provider))
        , _adapter(std::move(adapter))
    {
    }

    std::vector<Core::Character> JsonCharacterProvider::loadCharacters()
    {
        throw std::runtime_error("Not implemented");
    }

    Core::Character JsonCharacterProvider::loadCharacter(const std::string& firstName, const std::string& lastName)
    {
        std::stringstream filename;
        filename << firstName << JsonUtils::UNDERSCORE << lastName << JsonUtils::JSON_EXTENSION;

        auto characterDto = _provider.readItem(filename.str());
        return _adapter.toCharacter(characterDto);
    }


    void JsonCharacterProvider::saveCharacter(const Core::Character& character)
    {
        throw std::runtime_error("Not implemented");
    }

    void JsonCharacterProvider::deleteCharacter(const std::string firstName, const std::string lastName)
    {
        throw std::runtime_error("Not implemented");
    }


}
