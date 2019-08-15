#include "characters_provider.h"

#include <QDir>

#include "reader/character_reader.h"

CharactersProvider::CharactersProvider(const QString &folderPath)
{
    QDir directory(folderPath);
    QStringList files = directory.entryList(QStringList() << "*.json", QDir::Files);
    foreach(const QString& filename, files) {
        _characters.push_back(std::make_shared<Character>(CharacterReader::readCharacterFromFile(directory.filePath(filename))));
    }

    QSet<QString> ethnies;
    QSet<QString> groups;

    foreach(const std::shared_ptr<Character>& character, _characters) {
        foreach (const QString& ethnie, character->getEthnies()) {
            ethnies.insert(ethnie);
        }

        foreach (const QString& group, character->getGroups()) {
            groups.insert(group);
        }
    }

    _ethnies = ethnies.toList();
    _ethnies.sort();
    _ethnies.prepend(QString());

    _groups = groups.toList();
    _groups.sort();
    _groups.prepend(QString());
}

QList<std::shared_ptr<Character>> CharactersProvider::characters() const
{
    return _characters;
}

QList<QString> CharactersProvider::ethnies() const
{
    return _ethnies;
}

QList<QString> CharactersProvider::groups() const
{
    return _groups;
}

QList<std::shared_ptr<Character>> CharactersProvider::findCharacters(const std::function<bool (const std::shared_ptr<Character> &)> &predicate) const
{
    QList<std::shared_ptr<Character>> resultCharacters;
    std::copy_if(_characters.begin(), _characters.end(), std::back_inserter(resultCharacters), predicate);
    return resultCharacters;
}