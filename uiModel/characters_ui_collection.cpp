#include "characters_ui_collection.h"

#include <QQmlEngine>
#include <QStandardItemModel>

CharactersUiCollection::CharactersUiCollection()
    : QObject (nullptr)
    , _model(nullptr)
    , _charactersProvider(nullptr)
{

}

CharactersUiCollection::CharactersUiCollection(CharactersProvider *charactersProvider, QObject *parent)
    : QObject(parent)
    , _model(new QStandardItemModel(this))
    , _charactersProvider(charactersProvider)
{
    _model->insertColumn(0);
    addCharacters(_charactersProvider->characters());
}

void CharactersUiCollection::addCharacter(const std::shared_ptr<Character> &character)
{
    if (!character) return;

    const int newRow = _model->rowCount();
    std::shared_ptr<CharacterUiModel> characterUi = std::make_shared<CharacterUiModel>(character);
    QQmlEngine::setObjectOwnership(characterUi.get(), QQmlEngine::CppOwnership);
    _model->insertRow(newRow);
    _model->setData(_model->index(newRow, 0), QVariant::fromValue(characterUi.get()), Qt::DisplayRole);
    _characterUiModels.push_back(std::move(characterUi));
}

void CharactersUiCollection::clearCharacters()
{
    const int rowCount = _model->rowCount();
    _model->removeRows(0, rowCount);
    _characterUiModels.clear();
}

void CharactersUiCollection::addCharacters(const QList<std::shared_ptr<Character>>& characters)
{
    foreach (const std::shared_ptr<Character> &character, characters) {
        addCharacter(character);
    }
}

void CharactersUiCollection::filterCharacters(const QString &type, const QString &name)
{
    clearCharacters();

    QList<std::shared_ptr<Character>> characters;

    if (name == "Tous") {
        characters = _charactersProvider->characters();
    }

    else if (type == QString("group")) {
        characters = _charactersProvider->findCharacters([name](const std::shared_ptr<Character> &character)
        {
            auto groups = character->getGroups();
            auto it = std::find_if(groups.begin(), groups.end(),[name](auto group) { return QString::compare(name, group) == 0; });
            return it != groups.end();
        });
    }

    else if (type == QString("ethnie")) {
        characters = _charactersProvider->findCharacters([name](const std::shared_ptr<Character> &character)
        {
            auto ethnies = character->getEthnies();
            auto it = std::find_if(ethnies.begin(), ethnies.end(),[name](auto ethnie) { return QString::compare(name, ethnie) == 0; });
            return it != ethnies.end();
        });
    }

    else if (type == QString("nation")) {
        characters = _charactersProvider->findCharacters([name](const std::shared_ptr<Character> &character)
        {
            return QString::compare(name, character->getCurrentNation()) == 0;
        });
    }

    addCharacters(characters);
}

void CharactersUiCollection::refreshCharacters()
{
    clearCharacters();
    _charactersProvider->refreshCharacters();
    addCharacters(_charactersProvider->characters());
    emit charactersChanged();
}
