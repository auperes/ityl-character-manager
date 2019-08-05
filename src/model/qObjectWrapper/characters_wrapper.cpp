#include "characters_wrapper.h"

CharactersWrapper::CharactersWrapper(const CharactersProvider& charactersProvider, QObject *parent)
    : QObject(parent)
    , _charactersProvider(charactersProvider)
{
//    _characters = _charactersProvider.characters().toVector();
}
