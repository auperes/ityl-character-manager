#pragma once

#include <QString>

class AppConfig
{
public:
    AppConfig();

    QString getCharactersFolderPath() const;

    QString getAvatarsFolderPath() const;

private:
    QString _charactersFolderPath;
    QString _avatarsFolderPath;
};

