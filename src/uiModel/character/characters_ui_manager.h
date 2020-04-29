#pragma once

#include <QObject>

#include "characters_ui_collection.h"
#include "../../characters_provider.h"

namespace Ityl::UiModel
{
    class CharactersUiManager : public QObject
    {
        Q_OBJECT
    public:
        explicit CharactersUiManager(QObject *parent = nullptr);
        explicit CharactersUiManager(CharactersProvider *charactersProvider, const QMap<QString, QString>& nationColors, QObject *parent = nullptr);

        Q_INVOKABLE CharactersUiCollection* addCollection(const QString& type, const QString& name);
        Q_INVOKABLE void removeCollection(unsigned id);

    signals:

    public slots:
        void refreshCharacters();

    private:
        unsigned _idSequence = 0;
        CharactersProvider* _charactersProvider;
        QMap<unsigned, std::shared_ptr<CharactersUiCollection>> _charactersUiCollections;
        QMap<QString, QString> _nationColors;

        void refreshCharacters(CharactersUiCollection& collection);
        QList<std::shared_ptr<CharacterUiModel>> createModels(const FilteringType& filteringType, const QString& filteringName);
        QString getNationColor(const QString& nationName) const;
    };
}