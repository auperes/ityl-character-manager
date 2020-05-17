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
    QString AppConfig::_groupsFolderPath;
}
