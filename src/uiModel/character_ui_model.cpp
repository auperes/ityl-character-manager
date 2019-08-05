#include "character_ui_model.h"

CharacterUiModel::CharacterUiModel()
    : _character(nullptr)
{

}

CharacterUiModel::CharacterUiModel(const std::shared_ptr<Character> &character)
    : _character(character)
{

}

CharacterUiModel::CharacterUiModel(const CharacterUiModel &characterUiModel)
    : _character(characterUiModel._character)
{

}

const QString CharacterUiModel::fullName() const
{
    return _character->getFirstName() + " " + _character->getLastName();
}

const QString CharacterUiModel::avatar() const
{
    return "file:///" + _character->getAvatar();
}

const QString CharacterUiModel::quote() const
{
    return "« " + _character->getQuote() + " »";
}
