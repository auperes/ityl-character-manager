#pragma once

#include <memory>

#include <QAbstractListModel>

#include "qObjectWrapper/relationships_wrapper.h"

class RelationshipModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(std::shared_ptr<RelationshipsWrapper> relationships READ relationshipsWrapper WRITE setRelationshipsWrapper)

public:
    explicit RelationshipModel(QObject *parent = nullptr);

    enum {
        RelationshipTypeRole,
        RelationshipNamesRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    std::shared_ptr<RelationshipsWrapper> relationshipsWrapper() const;
    void setRelationshipsWrapper(std::shared_ptr<RelationshipsWrapper> relationshipsWrapper);

private:
    std::shared_ptr<RelationshipsWrapper> _relationshipsWrapper;
};
