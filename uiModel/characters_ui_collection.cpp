#include "characters_ui_collection.h"

#include <QQmlEngine>
#include <QStandardItemModel>

CharactersUiCollection::CharactersUiCollection()
    : QObject (nullptr)
    , _model(nullptr)
    , _charactersProvider(CharactersProvider(""))
{

}

CharactersUiCollection::CharactersUiCollection(const CharactersProvider &charactersProvider, QObject *parent)
    : QObject(parent)
    , _model(new QStandardItemModel(this))
    , _charactersProvider(charactersProvider)
{
    _model->insertColumn(0);
    foreach (const std::shared_ptr<Character> &character, _charactersProvider.characters()) {
        addCharacter(character);
    }
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

void CharactersUiCollection::filterCharacters(const QString &type, const QString &name)
{
    const int rowCount = _model->rowCount();
    _model->removeRows(0, rowCount);

    QVector<std::shared_ptr<Character>> characters;

    if (name == "Tous") {
        characters = _charactersProvider.characters().toVector();
    }

    else if (type == QString("group")) {
        characters = _charactersProvider.findCharacters([name](const std::shared_ptr<Character> &character)
        {
            auto groups = character->getGroups();
            auto it = std::find_if(groups.begin(), groups.end(),[name](auto group) { return QString::compare(name, group) == 0; });
            return it != groups.end();
        }).toVector();
    }

    else if (type == QString("ethnie")) {
        characters = _charactersProvider.findCharacters([name](const std::shared_ptr<Character> &character)
        {
            auto ethnies = character->getEthnies();
            auto it = std::find_if(ethnies.begin(), ethnies.end(),[name](auto ethnie) { return QString::compare(name, ethnie) == 0; });
            return it != ethnies.end();
        }).toVector();
    }

    else if (type == QString("nation")) {
        characters = _charactersProvider.findCharacters([name](const std::shared_ptr<Character> &character)
        {
            return QString::compare(name, character->getCurrentNation()) == 0;
        }).toVector();
    }

    foreach (auto character, characters) {
        addCharacter(character);
    }
}
