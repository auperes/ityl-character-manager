#pragma once

#include <QAbstractItemModel>
#include <QObject>

#include <homeView/home_element_type.h>

namespace Ityl::Ui::UiModels
{
    class HomeCategoryUiModel : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QStringList regions READ getRegions CONSTANT)
        Q_PROPERTY(QStringList organizations READ getOrganizations CONSTANT)
        Q_PROPERTY(QStringList families READ getFamilies CONSTANT)
        Q_PROPERTY(QStringList guilds READ getGuilds CONSTANT)
        Q_PROPERTY(QStringList groups READ getGroups CONSTANT)
        Q_PROPERTY(QStringList backgrounds READ getBackgrounds CONSTANT)
        Q_PROPERTY(QStringList ethnies READ getEthnies CONSTANT)

    public:
        explicit HomeCategoryUiModel(QObject *parent = nullptr);
        explicit HomeCategoryUiModel(const QMap<DataModel::HomeElementType, QList<QString>>& elements, QObject *parent = nullptr);

        ~HomeCategoryUiModel() override = default;

        QList<QString> getRegions() const { return _regions; }
        QList<QString> getOrganizations() const { return _organizations; }
        QList<QString> getFamilies() const { return _families; }
        QList<QString> getGuilds() const { return _guilds; }
        QList<QString> getGroups() const { return _groups; }
        QList<QString> getBackgrounds() const { return _backgrounds; }
        QList<QString> getEthnies() const { return _ethnies; }

    signals:

    private:
        QList<QString> _regions;
        QList<QString> _organizations;
        QList<QString> _families;
        QList<QString> _guilds;
        QList<QString> _groups;
        QList<QString> _backgrounds;
        QList<QString> _ethnies;
    };
}
