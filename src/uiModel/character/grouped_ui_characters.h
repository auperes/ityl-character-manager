#pragma once

#include <memory>

#include "characters_ui_collection.h"

namespace Ityl::UiModel
{
    struct GroupedUiCharacters
    {
    public:
        GroupedUiCharacters() {}

        GroupedUiCharacters(
                const std::shared_ptr<CharactersUiCollection>& currentUiCharacters,
                const std::shared_ptr<CharactersUiCollection>& oldUiCharacters)
            : _currentUiCharacters(currentUiCharacters)
            , _oldUiCharacters(oldUiCharacters)
        {}

        std::shared_ptr<CharactersUiCollection> _currentUiCharacters;
        std::shared_ptr<CharactersUiCollection> _oldUiCharacters;
    };
}
