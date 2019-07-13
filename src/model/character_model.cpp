#include "character_model.h"

CharacterModel::CharacterModel(QObject *parent)
    : QAbstractListModel(parent)
    , _charactersWrapper(nullptr)
{
}

int CharacterModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return _charactersWrapper->characters().size();
}

QVariant CharacterModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Character character = _charactersWrapper->characters().at(index.row());
    switch (role) {
    case FullNameRole:
        return QVariant(QString(character.getFirstName() + " " + character.getLastName()));
    case BirthNameRole:
        return QVariant();
        //TODO
//        return QVariant(character.getBirthName());
    case TitleRole:
        return QVariant(character.getTitle());
    case QuoteRole:
        return QVariant(QString("« " + character.getQuote() + " »"));
    case AvatarRole:
        return QVariant(QString("file:///" + character.getAvatar()));
    case BirthPlaceRole:
        return QVariant(character.getBirthPlace());
    case LivelyPlaceRole:
        return QVariant(character.getLivelyPlace());
    case StatusRole:
        return QVariant();
        //TODO
//        return QVariant(character.getStatus());
    case DescriptionRole:
        return QVariant(character.getDescription());
    case RolesRole:
    {
        QStringList rolesList(character.getRoles().toList());
        return QVariant::fromValue(rolesList);
    }
    case SkillsRole:
        return QVariant::fromValue<std::shared_ptr<SkillsWrapper>>(std::make_shared<SkillsWrapper>(character.getSkills()));
    case RelationshipsRole:
        return QVariant::fromValue<std::shared_ptr<RelationshipsWrapper>>(std::make_shared<RelationshipsWrapper>(character.getRelationships()));
    case EthniesRole:
    {
        QStringList ethniesList(character.getEthnies().toList());
        return QVariant::fromValue(ethniesList);
    }
    case GroupsRole:
    {
        QStringList groupsList(character.getGroups().toList());
        return QVariant::fromValue(groupsList);
    }
    }

    return QVariant();
}

QHash<int, QByteArray> CharacterModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[FullNameRole] = "fullName";
    names[BirthNameRole] = "birthName";
    names[TitleRole] = "title";
    names[QuoteRole] = "quote";
    names[AvatarRole] = "avatar";
    names[BirthPlaceRole] = "birthPlace";
    names[LivelyPlaceRole] = "livelyPlace";
    names[StatusRole] = "status";
    names[DescriptionRole] = "description";
    names[RolesRole] = "characterRoles";
    names[SkillsRole] = "skills";
    names[RelationshipsRole] = "relationships";
    names[EthniesRole] = "ethnies";
    names[GroupsRole] = "groups";
    return names;
}

CharactersWrapper* CharacterModel::charactersWrapper() const
{
    return _charactersWrapper;
}

void CharacterModel::setCharactersWrapper(CharactersWrapper* charactersWrapper)
{
    beginResetModel();

    if (_charactersWrapper)
        _charactersWrapper->disconnect(this);

    _charactersWrapper = charactersWrapper;

    endResetModel();
}
