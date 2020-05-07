#pragma once

#include <memory>

#include <QDir>
#include <QList>
#include <QString>

#include "../dataModel/character/character.h"

namespace Ityl::Provider
{
    class CharactersProvider
    {
    public:
        CharactersProvider(const QString &folderPath);

        QList<std::shared_ptr<DataModel::Character>> getCharacters() const { return _characters; }

        void setFolderPath(const QString& folderPath) { _folder = QDir(folderPath); }

        void refreshCharacters();
        QList<std::shared_ptr<DataModel::Character>> findCharacters(const std::function<bool (const std::shared_ptr<DataModel::Character>&)> &predicate) const;


    private:
        QDir _folder;
        QList<std::shared_ptr<DataModel::Character>> _characters;

        void loadCharacters();
    };
}
