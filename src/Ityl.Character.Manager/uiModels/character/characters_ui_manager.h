#pragma once

#include <QObject>

#include <providers/characters_provider.h>

#include "characters_ui_collection.h"
#include "../../models/character/grouped_ui_characters.h"

namespace Ityl::Ui::UiModels
{
    class CharactersUiManager : public QObject
    {
        Q_OBJECT
    public:
        CharactersUiManager(const QString& charactersFolderPath, const QMap<QString, QString>& nationColors, QObject *parent = nullptr);

        ~CharactersUiManager() override = default;

        Q_INVOKABLE CharactersUiCollection* addCollection(const QString& type, const QString& name);
        Q_INVOKABLE void removeCollection(unsigned id);

        QMap<QString, Models::GroupedUiCharacters> getCollectionsFromGroup(const QString& groupName);
        std::shared_ptr<CharactersUiCollection> getCollectionsFromEthnie(const QString& ethnieName);

    signals:

    public slots:
        void refreshCharacters();
        void changeCharactersLocation(const QString& folderPath);
        void changeNationColors(const QMap<QString, QString>& nationColors);

    private:
        unsigned _idSequence = 0;
        Business::Providers::CharactersProvider _charactersProvider;
        QMap<unsigned, std::shared_ptr<CharactersUiCollection>> _charactersUiCollections;
        QMap<QString, QString> _nationColors;

        void refreshCollection(CharactersUiCollection& collection);
        QList<std::shared_ptr<CharacterUiModel>> createModels(const Models::FilteringData& filteringData);
        QString getNationColor(const QString& nationName) const;
        QList<std::shared_ptr<CharacterUiModel>> toUiModel(const QList<std::shared_ptr<DataModel::Character>>& characters);
    };
}
