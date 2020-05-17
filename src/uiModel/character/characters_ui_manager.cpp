#include "characters_ui_manager.h"

#include <iostream>

#include <QQmlEngine>

#include "../../converters/converters.h"
#include "../../dataModel/app_config.h"

namespace Ityl::UiModel
{
    CharactersUiManager::CharactersUiManager(const QString& charactersFolderPath, const QMap<QString, QString>& nationColors, QObject *parent)
        : QObject(parent)
        , _charactersProvider(Provider::CharactersProvider(charactersFolderPath))
        , _nationColors(std::move(nationColors))
    {
    }

    CharactersUiCollection* CharactersUiManager::addCollection(const QString& type, const QString& name)
    {
        auto filteringType = DataModel::Converters::Converters::convertFilteringType(type);
        FilteringData filteringData(filteringType, name, "");
        auto characterUiModels = createModels(filteringData);
        auto charactersUiCollection = std::make_shared<CharactersUiCollection>(_idSequence, std::move(characterUiModels), filteringData);
        _charactersUiCollections.insert(_idSequence++, charactersUiCollection);

        QQmlEngine::setObjectOwnership(charactersUiCollection.get(), QQmlEngine::CppOwnership);

        return charactersUiCollection.get();
    }

    void CharactersUiManager::removeCollection(unsigned id)
    {
        _charactersUiCollections.remove(id);
    }

    QMap<QString, GroupedUiCharacters> CharactersUiManager::getCollectionsFromGroup(const QString& groupName)
    {
        auto charactersBySubgroup = _charactersProvider.findGroupedCharactersBySubgroups(groupName);
        QMap<QString, GroupedUiCharacters> groupedUiCharactersBySubgroup;

        for (const auto& subgroup : charactersBySubgroup.keys())
        {
            auto groupedCharacters = charactersBySubgroup[subgroup];
            FilteringData filteringData(FilteringType::Group, groupName, subgroup);
            auto currentUiCharacters = std::make_shared<CharactersUiCollection>(_idSequence, toUiModel(groupedCharacters._currentCharacters), filteringData);
//            _charactersUiCollections.insert(_idSequence++, currentUiCharacters); //TODO need to handle reload
            auto oldUiCharacters = std::make_shared<CharactersUiCollection>(_idSequence, toUiModel(groupedCharacters._oldCharacters), filteringData);
//            _charactersUiCollections.insert(_idSequence++, oldUiCharacters);

            GroupedUiCharacters groupedUiCharacters(currentUiCharacters, oldUiCharacters);
            groupedUiCharactersBySubgroup.insert(subgroup, groupedUiCharacters);
        }

        return groupedUiCharactersBySubgroup;
    }

    std::shared_ptr<CharactersUiCollection> CharactersUiManager::getCollectionsFromEthnie(const QString& ethnieName)
    {
        auto characters = _charactersProvider.findCharactersFromEthnie(ethnieName);
        auto characterUiModels = toUiModel(characters);
        FilteringData filteringData(FilteringType::Ethnie, ethnieName, "");
        auto charactersUiCollection = std::make_shared<CharactersUiCollection>(_idSequence, std::move(characterUiModels), filteringData);
//        _charactersUiCollections.insert(_idSequence++, charactersUiCollection); //TODO need to handle reload

        return charactersUiCollection;
    }

    void CharactersUiManager::refreshCharacters()
    {
        _charactersProvider.refreshCharacters();
        for (auto& collection : _charactersUiCollections)
            refreshCollection(*collection);
    }

    void CharactersUiManager::changeNationColors(const QMap<QString, QString>& nationColors)
    {
        _nationColors = nationColors;
    }

    void CharactersUiManager::changeCharactersLocation(const QString& folderPath)
    {
        _charactersProvider.setFolderPath(folderPath);
        refreshCharacters();
    }

    void CharactersUiManager::refreshCollection(CharactersUiCollection& collection)
    {
        collection.clearCharacters();
        auto characterUiModels = createModels(collection.getFilteringData());
        collection.setCharacters(std::move(characterUiModels));
    }

    QList<std::shared_ptr<CharacterUiModel> > CharactersUiManager::createModels(const FilteringData& filteringData)
    {
        QList<std::shared_ptr<DataModel::Character>> characters;
        switch (filteringData._type)
        {
        case FilteringType::None:
            characters = _charactersProvider.getAllCharacters();
            break;
        case FilteringType::Group:
            characters = _charactersProvider.findCharactersFromGroup(filteringData._name, filteringData._subname);
            break;
        case FilteringType::Ethnie:
            characters = _charactersProvider.findCharactersFromEthnie(filteringData._name);
            break;
        case FilteringType::Nation:
            characters = _charactersProvider.findCharactersFromNation(filteringData._name);
            break;
        }

        return toUiModel(characters);
    }

    QString CharactersUiManager::getNationColor(const QString& nationName) const
    {
        if (_nationColors.contains(nationName))
            return _nationColors[nationName];

        std::string errorMessage("Cannot convert nation. Unknown value: " + nationName.toStdString());
        std::cout << errorMessage << std::endl;

        return "#969696";
    }

    QList<std::shared_ptr<CharacterUiModel> > CharactersUiManager::toUiModel(const QList<std::shared_ptr<DataModel::Character> >& characters)
    {
        QList<std::shared_ptr<CharacterUiModel>> characterUiModels;
        for (const std::shared_ptr<DataModel::Character>& character : characters)
            characterUiModels.push_back(std::make_shared<CharacterUiModel>(character, getNationColor(character->getCurrentNation())));

        return characterUiModels;
    }
}
