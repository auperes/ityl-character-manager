#pragma once

#include <memory>

#include <QDir>
#include <QList>
#include <QString>

#include <character/character.h>

#include "../models/grouped_characters.h"

namespace Ityl::Business::Providers
{
    class CharactersProvider
    {
    public:
        CharactersProvider(const QString &folderPath);

        QList<std::shared_ptr<DataModel::Character>> getAllCharacters() const { return _characters; }

        void setFolderPath(const QString& folderPath) { _folder = QDir(folderPath); }

        void refreshCharacters();
        QList<std::shared_ptr<DataModel::Character>> findCharacters(const std::function<bool (const std::shared_ptr<DataModel::Character>&)> &predicate) const;
        QList<std::shared_ptr<DataModel::Character>> findCharactersFromEthnie(const QString& ethnieName);
        QList<std::shared_ptr<DataModel::Character>> findCharactersFromGroup(const QString& groupName);
        QList<std::shared_ptr<DataModel::Character>> findCharactersFromGroup(const QString& groupName, const QString& groupSubname);
        QList<std::shared_ptr<DataModel::Character>> findCharactersFromNation(const QString& nationName);

        QMap<QString, Models::GroupedCharacters> findGroupedCharactersBySubgroups(const QString& groupName);

    private:
        QDir _folder;
        QList<std::shared_ptr<DataModel::Character>> _characters;

        void loadCharacters();
    };
}
