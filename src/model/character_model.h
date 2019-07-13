#pragma once

#include <QAbstractListModel>
#include <QSharedDataPointer>
#include <QStringList>

#include "qObjectWrapper/characters_wrapper.h"
#include "qObjectWrapper/skills_wrapper.h"
#include "qObjectWrapper/relationships_wrapper.h"

Q_DECLARE_METATYPE(std::shared_ptr<SkillsWrapper>)
Q_DECLARE_METATYPE(std::shared_ptr<RelationshipsWrapper>)

class CharacterModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(CharactersWrapper *characters READ charactersWrapper WRITE setCharactersWrapper)

public:
    explicit CharacterModel(QObject *parent = nullptr);

    enum {
        FullNameRole = Qt::UserRole,
        BirthNameRole,
        TitleRole,
        QuoteRole,
        AvatarRole,
        BirthPlaceRole,
        LivelyPlaceRole,
        StatusRole,
        DescriptionRole,
        RolesRole,
        SkillsRole,
        RelationshipsRole,
        EthniesRole,
        GroupsRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    CharactersWrapper* charactersWrapper() const;
    void setCharactersWrapper(CharactersWrapper* charactersWrapper);

private:
    CharactersWrapper* _charactersWrapper;
};
