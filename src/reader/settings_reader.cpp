#include "settings_reader.h"

#include <QJsonObject>

#include "../dataModel/app_config.h"
#include "json_reader_helpers.h"

namespace Ityl::Reader
{
    bool SettingsReader::readSettingsFromFile(const QString& filepath)
    {
        QJsonObject settings = JsonReaderHelpers::readJsonFile(filepath);

        if (!isSettings(settings))
            return false;

        DataModel::AppConfig::setCharactersFolderPath(settings["charactersFolderPath"].toString());
        DataModel::AppConfig::setGroupsFolderPath(settings["groupsFolderPath"].toString());
        DataModel::AppConfig::setAvatarsFolderPath(settings["avatarsFolderPath"].toString());
        DataModel::AppConfig::setRelatedRelationshipsFilePath(settings["relatedRelationshipsFilePath"].toString());
        DataModel::AppConfig::setLogFolderPath(settings["logFolderPath"].toString());
        DataModel::AppConfig::setHomeViewFilePath(settings["homeViewFilePath"].toString());
        DataModel::AppConfig::setColorsFilePath(settings["colorsFilePath"].toString());

        return true;
    }

    bool SettingsReader::isSettings(const QJsonObject& settings)
    {
        if (!settings.contains("charactersFolderPath")) return false;
        if (!settings.contains("groupsFolderPath")) return false;
        if (!settings.contains("avatarsFolderPath")) return false;
        if (!settings.contains("relatedRelationshipsFilePath")) return false;
        if (!settings.contains("logFolderPath")) return false;
        if (!settings.contains("homeViewFilePath")) return false;
        if (!settings.contains("colorsFilePath")) return false;

        return true;
    }
}
