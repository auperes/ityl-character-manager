#pragma once

#include <memory>

#include "../../uiModels/character/characters_ui_collection.h"

namespace Ityl::Ui::Models
{
    struct GroupedUiCharacters
    {
    public:
        GroupedUiCharacters() {}

        GroupedUiCharacters(
                const std::shared_ptr<UiModels::CharactersUiCollection>& currentUiCharacters,
                const std::shared_ptr<UiModels::CharactersUiCollection>& oldUiCharacters)
            : _currentUiCharacters(currentUiCharacters)
            , _oldUiCharacters(oldUiCharacters)
        {}

        std::shared_ptr<UiModels::CharactersUiCollection> _currentUiCharacters;
        std::shared_ptr<UiModels::CharactersUiCollection> _oldUiCharacters;
    };
}
