#pragma once

#include <QObject>

#include "characters_ui_collection.h"
#include "../../provider/characters_provider.h"

namespace Ityl::UiModel
{
    class CharactersUiManager : public QObject
    {
        Q_OBJECT
    public:
        CharactersUiManager(const QString& charactersFolderPath, const QMap<QString, QString>& nationColors, QObject *parent = nullptr);

        Q_INVOKABLE CharactersUiCollection* addCollection(const QString& type, const QString& name);
        Q_INVOKABLE void removeCollection(unsigned id);

    signals:

    public slots:
        void refreshCharacters();
        void changeCharactersLocation(const QString& folderPath);
        void changeNationColors(const QMap<QString, QString>& nationColors);

    private:
        unsigned _idSequence = 0;
        Provider::CharactersProvider _charactersProvider;
        QMap<unsigned, std::shared_ptr<CharactersUiCollection>> _charactersUiCollections;
        QMap<QString, QString> _nationColors;

        void refreshCollection(CharactersUiCollection& collection);
        QList<std::shared_ptr<CharacterUiModel>> createModels(const FilteringType& filteringType, const QString& filteringName);
        QString getNationColor(const QString& nationName) const;
    };
}
