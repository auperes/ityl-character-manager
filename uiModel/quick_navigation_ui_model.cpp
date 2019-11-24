#include "quick_navigation_ui_model.h"

QuickNavigationUiModel::QuickNavigationUiModel(CharactersProvider* charactersProvider, QObject *parent)
    : QObject(parent)
    , _nations(std::make_unique<QStringListModel>())
    , _ethnies(std::make_unique<QStringListModel>())
    , _groups(std::make_unique<QStringListModel>())
    , _charactersProvider(charactersProvider)
{
    refreshElements();
}

void QuickNavigationUiModel::refreshElements()
{
    _nations->setStringList(_charactersProvider->nations());
    _ethnies->setStringList(_charactersProvider->ethnies());
    _groups->setStringList(_charactersProvider->groups());
}
