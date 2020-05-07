#include "characters_provider.h"

#include <iostream>

#include <QDir>
#include <QSet>

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
}
