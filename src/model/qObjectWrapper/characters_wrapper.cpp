#include "characters_wrapper.h"

CharactersWrapper::CharactersWrapper(QObject *parent) : QObject(parent)
{

}

void CharactersWrapper::appendCharacter(const Character &character)
{
    _characters.append(character);
}
