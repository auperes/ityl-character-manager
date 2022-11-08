#pragma once

#include <back_api/character_provider.h>
#include <model/character.h>

#include "adapter/character_adapter.h"
#include "json_item_provider.h"
#include "model/character_dto.h"

namespace Ityl::Json
{
    class JsonCharacterProvider : public Core::Interface::CharacterProvider
    {
    public:
        JsonCharacterProvider(JsonItemProvider<CharacterDto>&& provider, CharacterAdapter&& adapter);
        virtual ~JsonCharacterProvider() = default;

        std::vector<Core::Character> loadCharacters() override;
        Core::Character loadCharacter(const std::string& firstName, const std::string& lastName) override;
        void saveCharacter(const Core::Character& character) override;
        void deleteCharacter(const std::string firstName, const std::string lastName) override;

    private:
        JsonItemProvider<CharacterDto> _provider;
        CharacterAdapter _adapter;
    };
}
