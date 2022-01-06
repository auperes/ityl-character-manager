#pragma once

#include <memory>

#include <QList>

#include <character/character.h>

namespace Ityl::Business::Models
{
    struct GroupedCharacters
    {
        QList<std::shared_ptr<DataModel::Character>> _currentCharacters;
        QList<std::shared_ptr<DataModel::Character>> _oldCharacters;
    };
}
