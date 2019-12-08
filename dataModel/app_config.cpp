#include "app_config.h"

#include <QDir>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>

QString AppConfig::_charactersFolderPath;
QString AppConfig::_avatarsFolderPath;
QString AppConfig::_relatedRelationshipsFilePath;
QString AppConfig::_logFolderPath;

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
}

QString AppConfig::getCharactersFolderPath()
{
    return _charactersFolderPath;
}

QString AppConfig::getAvatarsFolderPath()
{
    return _avatarsFolderPath;
}

QString AppConfig::getRelatedRelationshipsFilePath()
{
    return _relatedRelationshipsFilePath;
}

QString AppConfig::getLogFolderPath()
{
    return _logFolderPath;
}