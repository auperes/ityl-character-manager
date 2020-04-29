#include "characters_provider.h"

#include <iostream>

#include <QDir>
#include <QSet>

#include "reader/character_reader.h"
#include "services/relationship_validator_service.h"

namespace Ityl
{
    CharactersProvider::CharactersProvider(const QString &folderPath)
        : _folderPath(folderPath)
    {
        loadCharacters();
    }

    void CharactersProvider::loadCharacters()
    {
        QDir directory(_folderPath);
        QStringList files = directory.entryList(QStringList() << "*.json", QDir::Files);

        foreach(const QString& filename, files) {
            try
            {
                _characters.push_back(std::make_shared<DataModel::Character>(Reader::CharacterReader::readCharacterFromFile(directory.filePath(filename))));
            }
            catch (const std::logic_error& ex)
            {
                std::cout << "Warning: An error occured when reading file " << filename.toStdString() << " (" << ex.what() << ")." << std::endl;
            }
        }

        QSet<QString> ethnies;
        QSet<QString> groups;
        QSet<QString> nations;
        Services::RelationshipValidatorService relationshipValidatorService;

        foreach(const std::shared_ptr<DataModel::Character>& character, _characters) {
            foreach (const QString& ethnie, character->getEthnies()) {
                ethnies.insert(ethnie);
            }

            foreach (const QString& group, character->getGroups()) {
                groups.insert(group);
            }

            nations.insert(character->getCurrentNation());

            QString characterFullName = character->getFirstName() + " " + character->getLastName();
            relationshipValidatorService.addCharacterName(characterFullName);
            auto relationships = character->getRelationships().keys();
            for (const DataModel::Relationship& relationship : relationships) {
                auto relationshipNames = character->getRelationships().value(relationship);
                for (auto& name : relationshipNames)
                {
                    QString relatedFullName = name.first + " " + name.second;
                    relationshipValidatorService.addRelationship(characterFullName, relationship, relatedFullName);
                }
            }
        }

        _ethnies = QStringList(ethnies.begin(), ethnies.end());
        _ethnies.sort();
        _ethnies.prepend(QString("Tous"));

        _groups = QStringList(groups.begin(), groups.end());
        _groups.sort();
        _groups.prepend(QString("Tous"));

        _nations = QStringList(nations.begin(), nations.end());
        _nations.sort();
        _nations.prepend(QString("Tous"));

        relationshipValidatorService.logMissingRelationships();
    }

    void CharactersProvider::refreshCharacters()
    {
        _characters.clear();
        _ethnies.clear();
        _groups.clear();
        _nations.clear();

        loadCharacters();
    }

    QList<std::shared_ptr<DataModel::Character>> CharactersProvider::characters() const
    {
        return _characters;
    }

    QStringList CharactersProvider::ethnies() const
    {
        return _ethnies;
    }

    QStringList CharactersProvider::groups() const
    {
        return _groups;
    }

    QList<std::shared_ptr<DataModel::Character>> CharactersProvider::findCharacters(const std::function<bool (const std::shared_ptr<DataModel::Character> &)> &predicate) const
    {
        QList<std::shared_ptr<DataModel::Character>> resultCharacters;
        std::copy_if(_characters.begin(), _characters.end(), std::back_inserter(resultCharacters), predicate);
        return resultCharacters;
    }

    QStringList CharactersProvider::nations() const
    {
        return _nations;
    }
}
