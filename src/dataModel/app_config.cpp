#include "app_config.h"

#include <QDir>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>

namespace Ityl::DataModel
{
    QString AppConfig::_charactersFolderPath;
    QString AppConfig::_avatarsFolderPath;
    QString AppConfig::_relatedRelationshipsFilePath;
    QString AppConfig::_logFolderPath;
    QString AppConfig::_homeViewFilePath;
    QString AppConfig::_colorsFilePath;

    void AppConfig::setCharactersFolderPath(const QString& charactersFolderPath)
    {
        _charactersFolderPath = charactersFolderPath;
    }

    void AppConfig::setAvatarsFolderPath(const QString& avatarsFolderPath)
    {
        _avatarsFolderPath = avatarsFolderPath;
    }

    void AppConfig::setRelatedRelationshipsFilePath(const QString& relatedRelationshipsFilePath)
    {
        _relatedRelationshipsFilePath = relatedRelationshipsFilePath;
    }

    void AppConfig::setLogFolderPath(const QString& logFolderPath)
    {
        _logFolderPath = logFolderPath;
    }

    void AppConfig::setHomeViewFilePath(const QString& homeViewFilePath)
    {
        _homeViewFilePath = homeViewFilePath;
    }

    void AppConfig::setColorsFilePath(const QString& colorsFilePath)
    {
        _colorsFilePath = colorsFilePath;
    }
}
