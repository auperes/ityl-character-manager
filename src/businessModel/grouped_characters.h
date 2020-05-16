#pragma once

#include <memory>

#include <QList>

#include "../dataModel/character/character.h"

namespace Ityl::BusinessModel
{
    struct GroupedCharacters
    {
        QList<std::shared_ptr<DataModel::Character>> _currentCharacters;
        QList<std::shared_ptr<DataModel::Character>> _oldCharacters;
    };
}
