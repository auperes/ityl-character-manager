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

    AppConfig::AppConfig()
    {
        QString content;
        QFile file;

        file.setFileName("settings/app_config.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        content = file.readAll();
        file.close();
        QJsonDocument document = QJsonDocument::fromJson(content.toUtf8());
        QJsonObject jsonObject = document.object();

        if (jsonObject.contains("charactersFolderPath"))
            _charactersFolderPath = jsonObject["charactersFolderPath"].toString();
        if (jsonObject.contains("avatarsFolderPath"))
            _avatarsFolderPath = jsonObject["avatarsFolderPath"].toString();
        if (jsonObject.contains("relatedRelationshipsFilePath"))
            _relatedRelationshipsFilePath = jsonObject["relatedRelationshipsFilePath"].toString();
        if (jsonObject.contains("logFolderPath"))
            _logFolderPath = jsonObject["logFolderPath"].toString();
        if (jsonObject.contains("homeViewFilePath"))
            _homeViewFilePath = jsonObject["homeViewFilePath"].toString();
        if (jsonObject.contains("homeViewFilePath"))
            _colorsFilePath = jsonObject["colorsFilePath"].toString();
    }
}
