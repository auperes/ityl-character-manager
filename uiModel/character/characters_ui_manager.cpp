#include "characters_ui_manager.h"

#include <QQmlEngine>

#include "../../converters/converters.h"

namespace Ityl::UiModel
{
    CharactersUiManager::CharactersUiManager(QObject *parent)
        : QObject(parent)
        , _charactersProvider(nullptr)
    {

    }

    CharactersUiManager::CharactersUiManager(CharactersProvider *charactersProvider, QObject *parent)
        : QObject(parent)
        , _charactersProvider(charactersProvider)
    {

    }

    CharactersUiCollection* CharactersUiManager::addCollection(const QString& type, const QString& name)
    {
        auto filteringType = DataModel::Converters::Converters::convertFilteringType(type);
        auto characterUiModels = createModels(filteringType, name);
        auto charactersUiCollection = std::make_shared<CharactersUiCollection>(_idSequence, std::move(characterUiModels), filteringType, name);
        _charactersUiCollections.insert(_idSequence++, charactersUiCollection);

        QQmlEngine::setObjectOwnership(charactersUiCollection.get(), QQmlEngine::CppOwnership);

        return charactersUiCollection.get();
    }

    void CharactersUiManager::removeCollection(unsigned id)
    {
        _charactersUiCollections.remove(id);
    }

    void CharactersUiManager::refreshCharacters()
    {
        _charactersProvider->refreshCharacters();
        for (auto& collection : _charactersUiCollections)
            refreshCharacters(*collection);
    }

    void CharactersUiManager::refreshCharacters(CharactersUiCollection &collection)
    {
        collection.clearCharacters();
        auto characterUiModels = createModels(collection.filteringType(), collection.filteringName());
        collection.setCharacters(std::move(characterUiModels));
    }

    QList<std::shared_ptr<CharacterUiModel> > CharactersUiManager::createModels(const FilteringType &filteringType, const QString &filteringName)
    {
        QList<std::shared_ptr<DataModel::Character>> characters;
        switch (filteringType)
        {
        case FilteringType::None:
            characters = _charactersProvider->characters();
            break;
        case FilteringType::Group:
            characters = _charactersProvider->findCharacters([filteringName](const std::shared_ptr<DataModel::Character> &character)
            {
                auto groups = character->getGroups();
                auto it = std::find_if(groups.begin(), groups.end(),[filteringName](auto group) { return QString::compare(filteringName, group) == 0; });
                return it != groups.end();
            });
            break;
        case FilteringType::Ethnie:
            characters = _charactersProvider->findCharacters([filteringName](const std::shared_ptr<DataModel::Character> &character)
            {
                auto ethnies = character->getEthnies();
                auto it = std::find_if(ethnies.begin(), ethnies.end(),[filteringName](auto ethnie) { return QString::compare(filteringName, ethnie) == 0; });
                return it != ethnies.end();
            });
            break;
        case FilteringType::Nation:
            characters = _charactersProvider->findCharacters([filteringName](const std::shared_ptr<DataModel::Character> &character)
            {
                return QString::compare(filteringName, character->getCurrentNation()) == 0;
            });
            break;
        }

        QList<std::shared_ptr<CharacterUiModel>> characterUiModels;
        for (const std::shared_ptr<DataModel::Character>& character : characters)
            characterUiModels.push_back(std::make_shared<CharacterUiModel>(character));

        return characterUiModels;
    }
}