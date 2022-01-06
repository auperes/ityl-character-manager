#include "settings_ui_manager.h"

#include <iostream>

#include <QDir>

#include <reader/home_view_reader.h>
#include <reader/json_reader_helpers.h>
#include <reader/settings_reader.h>
#include <config/app_config.h>

namespace Ityl::Ui::UiModels
{
    SettingsUiManager::SettingsUiManager(QObject *parent) : QObject(parent)
    {

    }

    void SettingsUiManager::changeSettings(const QUrl& fileUrl)
    {
        auto settingsFilepath = QDir::currentPath() + "/settings/" + fileUrl.fileName();

        if (!copySettingsFile(fileUrl, settingsFilepath))
            return;

        if (!Reader::SettingsReader::readSettingsFromFile(settingsFilepath))
            return;

        auto nationColors = Reader::JsonReaderHelpers::readNationsColor(DataModel::AppConfig::getColorsFilePath());
        auto homeView = Reader::HomeViewReader::readHomeViewFromFile(DataModel::AppConfig::getHomeViewFilePath());

        emit nationColorsChanged(nationColors);
        emit charactersFolderPathChanged(DataModel::AppConfig::getCharactersFolderPath());
        emit groupsFolderPathChanged(DataModel::AppConfig::getGroupsFolderPath());
        emit homeViewChanged(homeView);
    }

    bool SettingsUiManager::copySettingsFile(const QUrl& fileUrl, const QString& newFilepath)
    {
        if (fileUrl.toLocalFile() == newFilepath)
            return true;

        if (!QFile::exists(newFilepath))
            return QFile::copy(fileUrl.toLocalFile(), newFilepath);

        unsigned count = 0;
        while(!QFile::copy(fileUrl.toLocalFile(), newFilepath) && count < 10)
        {
            QFile::remove(newFilepath);
            ++count;
        }

        if (!QFile::exists(newFilepath))
        {
            std::cout << "Could not copy new settings file " << fileUrl.fileName().toStdString() << ". Excess retry of 10." << std::endl;
            return false;
        }

        return true;
    }
}
