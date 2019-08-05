#include "characters_ui_collection.h"

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

QAbstractItemModel* CharactersUiCollection::model() const
{
    return _model.get();
}

void CharactersUiCollection::addCharacter(const std::shared_ptr<Character> &character)
{
    if (!character) return;

    const int newRow = _model->rowCount();
    const CharacterUiModel characterUi(character);
    _model->insertRow(newRow);
    _model->setData(_model->index(newRow, 0), QVariant::fromValue(characterUi), Qt::DisplayRole);
}

void CharactersUiCollection::filterCharacters(const QString &type, const QString &name)
{
    const int rowCount = _model->rowCount();
    _model->removeRows(0, rowCount);

    QVector<std::shared_ptr<Character>> characters;

    if (name == "") {
        characters = _charactersProvider.characters().toVector();
    }

    else if (type == QString("group")) {
        characters = _charactersProvider.findCharacters([name](const std::shared_ptr<Character> &character)
        {
        //TODO make this work
            return std::find(character->getGroups().begin(), character->getGroups().end(), name);
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

    foreach (auto character, characters) {
        addCharacter(character);
    }
}
