#include "character_ui_model.h"

#include <QQmlEngine>
#include <QStandardItemModel>
#include <QMap>

#include "skill_ui_model.h"

CharacterUiModel::CharacterUiModel()
    : _character(nullptr)
    , _skills(nullptr)
    , _relationships(nullptr)
{

}

CharacterUiModel::CharacterUiModel(const std::shared_ptr<Character> &character)
    : _character(character)
    , _skills(new QStandardItemModel(this))
    , _relationships(new QStandardItemModel(this))
{
    _skills->insertColumn(0);
    auto skills = _character->getSkills();

    for (auto skillName : skills.keys()) {
        addSkill(skillName, skills.value(skillName));
    }
}

CharacterUiModel::CharacterUiModel(const CharacterUiModel &characterUiModel)
    : _character(characterUiModel._character)
{

}

const QString CharacterUiModel::fullName() const
{
    return _character->getFirstName() + " " + _character->getLastName();
}

const QString CharacterUiModel::avatar() const
{
    return "file:///" + _character->getAvatar();
}

const QString CharacterUiModel::quote() const
{
    return "« " + _character->getQuote() + " »";
}

void CharacterUiModel::addSkill(const QString &skillName, const QList<Skill> &skillValues)
{
    const int newRow = _skills->rowCount();
    SkillUiModel* skillUi = new SkillUiModel(skillName, skillValues);
    QQmlEngine::setObjectOwnership(skillUi, QQmlEngine::JavaScriptOwnership);
    _skills->insertRow(newRow);
    _skills->setData(_skills->index(newRow, 0), QVariant::fromValue(skillUi), Qt::DisplayRole);
}

void CharacterUiModel::addRelationship(const QString &relationType, QList<QPair<QString, QString> > characterNames)
{

}
