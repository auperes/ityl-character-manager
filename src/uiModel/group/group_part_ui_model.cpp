#include "group_part_ui_model.h"

#include <QQmlEngine>
#include <QStandardItemModel>

namespace Ityl::UiModel
{
    GroupPartUiModel::GroupPartUiModel(const DataModel::GroupPart& part, QObject *parent)
        : QObject(parent)
        , _part(part)
        , _currentCharacters(std::make_shared<CharactersUiCollection>())
        , _oldCharacters(std::make_shared<CharactersUiCollection>())
    {
    }

    unsigned GroupPartUiModel::nameSize()
    {
        unsigned size = 16 - (_part.getNestedLevel() * 2);
        return size > 10 ? size : 11;
    }
}
