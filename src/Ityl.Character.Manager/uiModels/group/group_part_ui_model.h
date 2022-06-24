#pragma once

#include <QAbstractItemModel>
#include <QList>
#include <QObject>

#include <group/group_part.h>

#include "../character/characters_ui_collection.h"

namespace Ityl::Ui::UiModels
{
    class GroupPartUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString name READ name CONSTANT)
        Q_PROPERTY(unsigned nameSize READ nameSize CONSTANT)
        Q_PROPERTY(QString subgroupName READ subgroupName CONSTANT)
        Q_PROPERTY(QString description READ description CONSTANT)
        Q_PROPERTY(CharactersUiCollection* currentCharacters READ currentCharacters CONSTANT)
        Q_PROPERTY(CharactersUiCollection* oldCharacters READ oldCharacters CONSTANT)

    public:
        explicit GroupPartUiModel(const DataModel::GroupPart& part, QObject *parent = nullptr);

        ~GroupPartUiModel() override = default;

        const QString& name() { return _part.getPartName(); }
        unsigned nameSize();
        const QString& subgroupName() { return _part.getSubgroupName(); }
        const QString& description() { return _part.getDescription(); }
        CharactersUiCollection* currentCharacters() { return _currentCharacters.get(); }
        CharactersUiCollection* oldCharacters() { return _oldCharacters.get(); }

        void setCurrentCharactersUiCollection(std::shared_ptr<CharactersUiCollection> collection) { _currentCharacters = collection; }
        void setOldCharactersUiCollection(std::shared_ptr<CharactersUiCollection> collection) { _oldCharacters = collection; }

    signals:

    private:
        const DataModel::GroupPart& _part;

        std::shared_ptr<CharactersUiCollection> _currentCharacters;
        std::shared_ptr<CharactersUiCollection> _oldCharacters;
    };
}
