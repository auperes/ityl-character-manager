#include "app_config.h"

#include <QDir>
#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <iostream>

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
}

QString AppConfig::getCharactersFolderPath() const
{
    return _charactersFolderPath;
}

QString AppConfig::getAvatarsFolderPath() const
{
    return _avatarsFolderPath;
}
