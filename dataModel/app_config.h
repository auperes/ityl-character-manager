#pragma once

#include <QString>

class AppConfig
{
public:
    AppConfig();

    static QString getCharactersFolderPath();

    static QString getAvatarsFolderPath();

private:
    static QString _charactersFolderPath;
    static QString _avatarsFolderPath;
};

