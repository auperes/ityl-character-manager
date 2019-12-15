#include "characters_ui_collection.h"

#include <QQmlEngine>
#include <QStandardItemModel>

#include "../converters/converters.h"

CharactersUiCollection::CharactersUiCollection()
    : QObject (nullptr)
    , _model(nullptr)
    , _charactersProvider(nullptr)
    , _filteringType(FilteringType::None)
    , _filteringName("Tous")
{

}

CharactersUiCollection::CharactersUiCollection(CharactersProvider *charactersProvider, QObject *parent)
    : QObject(parent)
    , _model(new QStandardItemModel(this))
    , _charactersProvider(charactersProvider)
{
    _model->insertColumn(0);
    addCharacters(_charactersProvider->characters());
}

void CharactersUiCollection::addCharacter(const std::shared_ptr<Character> &character)
{
    if (!character) return;

    const int newRow = _model->rowCount();
    std::shared_ptr<CharacterUiModel> characterUi = std::make_shared<CharacterUiModel>(character);
    QQmlEngine::setObjectOwnership(characterUi.get(), QQmlEngine::CppOwnership);
    _model->insertRow(newRow);
    _model->setData(_model->index(newRow, 0), QVariant::fromValue(characterUi.get()), Qt::DisplayRole);
    _characterUiModels.push_back(std::move(characterUi));
}

void CharactersUiCollection::clearCharacters()
{
    const int rowCount = _model->rowCount();
    _model->removeRows(0, rowCount);
    _characterUiModels.clear();
}

void CharactersUiCollection::addCharacters(const QList<std::shared_ptr<Character>>& characters)
{
    foreach (const std::shared_ptr<Character> &character, characters) {
        addCharacter(character);
    }
}

void CharactersUiCollection::filterCharacters(const QString &type, const QString &name)
{
    FilteringType selectedType = Converters::convertFilteringType(type);
    _filteringType = (name == "Tous") ? FilteringType::None : selectedType;
    _filteringName = name;

    filterCharacters(_filteringType, _filteringName);

    emit filteringChanged(selectedType != Nation, selectedType != Ethnie, selectedType != Group);
}

void CharactersUiCollection::filterCharacters(const FilteringType &filteringType, const QString &filteringName)
{
    clearCharacters();

    QList<std::shared_ptr<Character>> characters;

    switch (filteringType)
    {
    case None:
        characters = _charactersProvider->characters();
        break;
    case Group:
        characters = _charactersProvider->findCharacters([filteringName](const std::shared_ptr<Character> &character)
        {
            auto groups = character->getGroups();
            auto it = std::find_if(groups.begin(), groups.end(),[filteringName](auto group) { return QString::compare(filteringName, group) == 0; });
            return it != groups.end();
        });
        break;
    case Ethnie:
        characters = _charactersProvider->findCharacters([filteringName](const std::shared_ptr<Character> &character)
        {
            auto ethnies = character->getEthnies();
            auto it = std::find_if(ethnies.begin(), ethnies.end(),[filteringName](auto ethnie) { return QString::compare(filteringName, ethnie) == 0; });
            return it != ethnies.end();
        });
        break;
    case Nation:
        characters = _charactersProvider->findCharacters([filteringName](const std::shared_ptr<Character> &character)
        {
            return QString::compare(filteringName, character->getCurrentNation()) == 0;
        });
        break;
    }

    addCharacters(characters);
}

void CharactersUiCollection::refreshCharacters()
{
    _charactersProvider->refreshCharacters();
    FilteringType currentType = _filteringType;
    bool needFilterReset = (_filteringType == Nation && !_charactersProvider->nations().contains(_filteringName))
            || (_filteringType == Ethnie && !_charactersProvider->ethnies().contains(_filteringName))
            || (_filteringType == Group && !_charactersProvider->groups().contains(_filteringName));

    if (needFilterReset)
    {
        _filteringType = None;
        _filteringName = "Tous";
    }

    filterCharacters(_filteringType, _filteringName);
    emit charactersChanged();

    if (needFilterReset)
        emit filteringChanged(currentType == Nation, currentType == Ethnie, currentType == Group);
}
