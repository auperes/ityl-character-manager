#include "characters_ui_collection.h"

#include <QQmlEngine>
#include <QStandardItemModel>

namespace Ityl::Ui::UiModels
{
    CharactersUiCollection::CharactersUiCollection()
        : QObject (nullptr)
        , _id(0)
        , _model(new QStandardItemModel(this))
        , _filteringData(Models::FilteringData(Models::FilteringType::None, "Tous", ""))
    {
        _model->insertColumn(0);
    }

    CharactersUiCollection::CharactersUiCollection(
            unsigned id,
            QList<std::shared_ptr<CharacterUiModel>>&& characterUiModels,
            Models::FilteringData filteringData,
            QObject* parent)
        : QObject(parent)
        , _id(id)
        , _model(new QStandardItemModel(this))
        , _characterUiModels(std::move(characterUiModels))
        , _filteringData(filteringData)
    {
        _model->insertColumn(0);
        addCharactersInternal(_characterUiModels);
    }

    void CharactersUiCollection::setCharacters(QList<std::shared_ptr<CharacterUiModel>>&& characterUiModels)
    {
        _characterUiModels = std::move(characterUiModels);
        addCharactersInternal(_characterUiModels);
    }

    void CharactersUiCollection::addCharacter(const std::shared_ptr<CharacterUiModel>& characterUiModel)
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
        _characterUiModels.append(characterUiModels);
        addCharactersInternal(characterUiModels);
    }

    void CharactersUiCollection::addCharactersInternal(const QList<std::shared_ptr<CharacterUiModel> >& characterUiModels)
    {
        for (const std::shared_ptr<CharacterUiModel>&characterUiModel : characterUiModels)
            addCharacter(characterUiModel);
    }
}
