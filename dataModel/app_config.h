#pragma once

#include <QString>

namespace Ityl::DataModel
{
    class AppConfig
    {
    public:
        AppConfig();

        static QString getCharactersFolderPath() { return _charactersFolderPath; }
        static QString getAvatarsFolderPath() { return _avatarsFolderPath; }
        static QString getRelatedRelationshipsFilePath() { return _relatedRelationshipsFilePath; }
        static QString getLogFolderPath() { return _logFolderPath; }
        static QString getHomeViewFilePath() { return _homeViewFilePath; }

    private:
        static QString _charactersFolderPath;
        static QString _avatarsFolderPath;
        static QString _relatedRelationshipsFilePath;
        static QString _logFolderPath;
        static QString _homeViewFilePath;
    };
}
