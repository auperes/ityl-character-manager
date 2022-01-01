#pragma once

#include <QObject>
#include <QUrl>
#include <QMap>

#include <homeView/home_view.h>

namespace Ityl::Ui::UiModels
{
    class SettingsUiManager : public QObject
    {
        Q_OBJECT
    public:
        explicit SettingsUiManager(QObject *parent = nullptr);

    signals:
        void charactersFolderPathChanged(const QString& folderPath);
        void groupsFolderPathChanged(const QString& folderPath);
        void homeViewChanged(const DataModel::HomeView& homeView);
        void nationColorsChanged(const QMap<QString, QString>& nationColors);

    public slots:
        void changeSettings(const QUrl& fileUrl);

    private:
        bool copySettingsFile(const QUrl& fileUrl, const QString& newFilepath);
    };
}

