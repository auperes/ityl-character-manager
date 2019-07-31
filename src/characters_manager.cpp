#include "characters_manager.h"

#include <QDir>

#include "reader/character_reader.h"

CharactersManager::CharactersManager(const QString &folderPath)
{
    QDir directory(folderPath);
    QStringList files = directory.entryList(QStringList() << "*.json", QDir::Files);
    foreach(const QString& filename, files) {
        _characters.push_back(CharacterReader::readCharacterFromFile(directory.filePath(filename)));
    }

    foreach(const Character& character, _characters) {
        foreach (const QString& ethnie, character.getEthnies()) {
            _ethnies.push_back(ethnie);
        }
    }

//    std::for_each(_characters.begin(), _characters.end(),
//                   [&](const Character& c) { std::copy(c.getEthnies().begin(), c.getEthnies().end(), std::back_inserter(_ethnies)); }
//    );
    std::sort(_ethnies.begin(), _ethnies.end());
    _ethnies.erase(std::unique(_ethnies.begin(), _ethnies.end()), _ethnies.end());
}

QList<Character> CharactersManager::characters() const
{
    return _characters;
}

QList<QString> CharactersManager::ethnies() const
{
    return _ethnies;
}

QList<QString> CharactersManager::groups() const
{
    return _groups;
}

QList<Character> CharactersManager::findCharacters(const std::function<bool (const Character &)> &predicate)
{
    QList<Character> resultCharacters;
    std::copy_if(_characters.begin(), characters().end(), std::back_inserter(resultCharacters), predicate);
    return resultCharacters;
}
