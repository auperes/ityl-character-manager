#pragma once

#include <QObject>
#include <QStringListModel>

#include "../characters_provider.h"

class QuickNavigationUiModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringListModel *nations READ nations CONSTANT)
    Q_PROPERTY(QStringListModel *ethnies READ ethnies CONSTANT)
    Q_PROPERTY(QStringListModel *groups READ groups CONSTANT)

public:
    explicit QuickNavigationUiModel(CharactersProvider* charactersProvider, QObject *parent = nullptr);

    QStringListModel *nations() const { return _nations.get();}
    QStringListModel *ethnies() const { return _ethnies.get(); }
    QStringListModel *groups() const { return _groups.get(); }

signals:

public slots:
    void refreshElements();

private:
    std::unique_ptr<QStringListModel> _nations;
    std::unique_ptr<QStringListModel> _ethnies;
    std::unique_ptr<QStringListModel> _groups;
    CharactersProvider *_charactersProvider;
};

