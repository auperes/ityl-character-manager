#pragma once

#include <QString>

namespace Ityl::DataModel
{
    class AppConfig
    {
    public:
        AppConfig();

        static QString getCharactersFolderPath();

        static QString getAvatarsFolderPath();

        static QString getRelatedRelationshipsFilePath();

        static QString getLogFolderPath();

    private:
        static QString _charactersFolderPath;
        static QString _avatarsFolderPath;
        static QString _relatedRelationshipsFilePath;
        static QString _logFolderPath;
    };
}
