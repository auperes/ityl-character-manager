#include "characters_ui_collection.h"

#include <QQmlEngine>
#include <QStandardItemModel>

#include "../../converters/converters.h"

namespace Ityl::UiModel
{
    CharactersUiCollection::CharactersUiCollection()
        : QObject (nullptr)
        , _id(0)
        , _model(nullptr)
        , _filteringType(FilteringType::None)
        , _filteringName("Tous")
    {

    }

    CharactersUiCollection::CharactersUiCollection(
            unsigned id,
            QList<std::shared_ptr<CharacterUiModel> > &&characterUiModels,
            FilteringType filteringType,
            QString filteringName,
            QObject *parent)
        : QObject(parent)
        , _id(id)
        , _model(new QStandardItemModel(this))
        , _characterUiModels(std::move(characterUiModels))
        , _filteringType(filteringType)
        , _filteringName(filteringName)
    {
        _model->insertColumn(0);
        addCharacters(_characterUiModels);
    }

    void CharactersUiCollection::setCharacters(QList<std::shared_ptr<CharacterUiModel> > &&characterUiModels)
    {
        _characterUiModels = std::move(characterUiModels);
        addCharacters(_characterUiModels);
    }

    void CharactersUiCollection::addCharacter(const std::shared_ptr<CharacterUiModel> &characterUiModel)
    {
        if (!characterUiModel) return;

        const int newRow = _model->rowCount();
        QQmlEngine::setObjectOwnership(characterUiModel.get(), QQmlEngine::CppOwnership);
        _model->insertRow(newRow);
        _model->setData(_model->index(newRow, 0), QVariant::fromValue(characterUiModel.get()), Qt::DisplayRole);
    }

    void CharactersUiCollection::clearCharacters()
    {
        const int rowCount = _model->rowCount();
        _model->removeRows(0, rowCount);
        _characterUiModels.clear();
    }

    void CharactersUiCollection::addCharacters(const QList<std::shared_ptr<CharacterUiModel>>& characterUiModels)
    {
        foreach (const std::shared_ptr<CharacterUiModel> &characterUiModel, characterUiModels) {
            addCharacter(characterUiModel);
        }
    }
}
