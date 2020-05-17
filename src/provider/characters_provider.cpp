#include "characters_provider.h"

#include <iostream>

#include <QDir>
#include <QSet>

#include "../dataModel/group/group.h"
#include "../reader/character_reader.h"
#include "../services/relationship_validator_service.h"

namespace Ityl::Provider
{
    CharactersProvider::CharactersProvider(const QString &folderPath)
        : _folder(QDir(folderPath))
    {
        loadCharacters();
    }

    void CharactersProvider::loadCharacters()
    {
        QStringList files = _folder.entryList(QStringList() << "*.json", QDir::Files);

        foreach(const QString& filename, files)
        {
            try
            {
                _characters.push_back(std::make_shared<DataModel::Character>(Reader::CharacterReader::readCharacterFromFile(_folder.filePath(filename))));
            }
            catch (const std::logic_error& ex)
            {
                std::cout << "Warning: An error occured when reading character file " << filename.toStdString() << " (" << ex.what() << ")." << std::endl;
            }
        }

        Services::RelationshipValidatorService relationshipValidatorService;

        foreach(const std::shared_ptr<DataModel::Character>& character, _characters)
        {
            QString characterFullName = character->getFirstName() + " " + character->getLastName();
            relationshipValidatorService.addCharacterName(characterFullName);
            auto relationships = character->getRelationships().keys();
            for (const DataModel::Relationship& relationship : relationships)
            {
                auto relationshipNames = character->getRelationships().value(relationship);
                for (auto& name : relationshipNames)
                {
                    QString relatedFullName = name.first + " " + name.second;
                    relationshipValidatorService.addRelationship(characterFullName, relationship, relatedFullName);
                }
            }
        }

        relationshipValidatorService.logMissingRelationships();
    }

    void CharactersProvider::refreshCharacters()
    {
        _characters.clear();
        loadCharacters();
    }

    QList<std::shared_ptr<DataModel::Character>> CharactersProvider::findCharacters(const std::function<bool (const std::shared_ptr<DataModel::Character> &)> &predicate) const
    {
        QList<std::shared_ptr<DataModel::Character>> resultCharacters;
        std::copy_if(_characters.begin(), _characters.end(), std::back_inserter(resultCharacters), predicate);
        return resultCharacters;
    }

    QList<std::shared_ptr<DataModel::Character> > CharactersProvider::findCharactersFromEthnie(const QString& ethnieName)
    {
        return findCharacters([ethnieName](const std::shared_ptr<DataModel::Character> &character)
        {
            auto ethnies = character->getEthnies();
            auto it = std::find_if(ethnies.begin(), ethnies.end(),[ethnieName](const auto& ethnie) { return QString::compare(ethnieName, ethnie.getName()) == 0; });
            return it != ethnies.end();
        });
    }

    QList<std::shared_ptr<DataModel::Character> > CharactersProvider::findCharactersFromGroup(const QString& groupName)
    {
        return findCharacters([groupName](const std::shared_ptr<DataModel::Character> &character)
        {
            auto groups = character->getGroups();
            auto it = std::find_if(groups.begin(), groups.end(),[groupName](const auto& group) { return QString::compare(groupName, group.getName()) == 0; });
            return it != groups.end();
        });
    }

    QList<std::shared_ptr<DataModel::Character> > CharactersProvider::findCharactersFromGroup(const QString& groupName, const QString& groupSubname)
    {
        auto subname = QString::compare(groupSubname, DataModel::Group::RootSubgroup) == 0 ? "" : groupSubname;

        return findCharacters([groupName, subname](const std::shared_ptr<DataModel::Character> &character)
        {
            auto groups = character->getGroups();
            auto it = std::find_if(
                        groups.begin(),
                        groups.end(),
                        [groupName, subname](const auto& group)
            {
                return (QString::compare(groupName, group.getName()) == 0) && (QString::compare(subname, group.getSubgroupName()));
            });

            return it != groups.end();
        });
    }

    QList<std::shared_ptr<DataModel::Character> > CharactersProvider::findCharactersFromNation(const QString& nationName)
    {
        return findCharacters([nationName](const std::shared_ptr<DataModel::Character>& character)
        {
            return QString::compare(nationName, character->getCurrentNation()) == 0;
        });
    }

    QMap<QString, BusinessModel::GroupedCharacters> CharactersProvider::findGroupedCharactersBySubgroups(const QString& groupName)
    {
        QMap<QString, BusinessModel::GroupedCharacters> charactersBySubgroup;
        charactersBySubgroup.insert(DataModel::Group::RootSubgroup, BusinessModel::GroupedCharacters());

        for (const auto& character : _characters)
        {
            for (const auto& groupInfo : character->getGroups())
            {
                if (QString::compare(groupName, groupInfo.getName()) == 0)
                {
                    auto subgroup = groupInfo.getSubgroupName().isEmpty() ? DataModel::Group::RootSubgroup : groupInfo.getSubgroupName();

                    if (groupInfo.getIsOld())
                        charactersBySubgroup[subgroup]._oldCharacters.push_back(character);
                    else
                        charactersBySubgroup[subgroup]._currentCharacters.push_back(character);
                }
            }
        }

        return charactersBySubgroup;
    }
}
