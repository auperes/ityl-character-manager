#pragma once

#include <memory>

#include <QList>
#include <QString>

#include "dataModel/character/character.h"

namespace Ityl
{
    class CharactersProvider
    {
    public:
        CharactersProvider(const QString &folderPath);

        QList<std::shared_ptr<DataModel::Character>> characters() const;
        QStringList ethnies() const;
        QStringList groups() const;
        QStringList nations() const;

        void refreshCharacters();
        QList<std::shared_ptr<DataModel::Character>> findCharacters(const std::function<bool (const std::shared_ptr<DataModel::Character>&)> &predicate) const;


    private:
        QString _folderPath;
        QList<std::shared_ptr<DataModel::Character>> _characters;
        QStringList _ethnies;
        QStringList _groups;
        QStringList _nations;

        void loadCharacters();
    };
}
