#pragma once

#include <memory>

#include <QDir>
#include <QList>
#include <QString>

#include "../businessModel/grouped_characters.h"
#include "../dataModel/character/character.h"

namespace Ityl::Provider
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

        QMap<QString, BusinessModel::GroupedCharacters> findCharactersBySubgroups(const QString& groupName);

    private:
        QDir _folder;
        QList<std::shared_ptr<DataModel::Character>> _characters;

        void loadCharacters();
    };
}
