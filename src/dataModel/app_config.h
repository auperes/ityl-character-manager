#pragma once

#include <QString>

namespace Ityl::DataModel
{
    class AppConfig
    {
    public:
        AppConfig() = delete;
        AppConfig(const AppConfig&) = delete;
        ~AppConfig() = delete;
        AppConfig& operator=(const AppConfig&) = delete;

        static QString getCharactersFolderPath() { return _charactersFolderPath; }
        static QString getAvatarsFolderPath() { return _avatarsFolderPath; }
        static QString getRelatedRelationshipsFilePath() { return _relatedRelationshipsFilePath; }
        static QString getLogFolderPath() { return _logFolderPath; }
        static QString getHomeViewFilePath() { return _homeViewFilePath; }
        static QString getColorsFilePath() { return _colorsFilePath; }
        static QString getGroupsFolderPath() { return _groupsFolderPath; }

        static void setCharactersFolderPath(const QString& charactersFolderPath) { _charactersFolderPath = charactersFolderPath; }
        static void setAvatarsFolderPath(const QString& avatarsFolderPath) { _avatarsFolderPath = avatarsFolderPath; }
        static void setRelatedRelationshipsFilePath(const QString& relatedRelationshipsFilePath) { _relatedRelationshipsFilePath = relatedRelationshipsFilePath; }
        static void setLogFolderPath(const QString& logFolderPath) { _logFolderPath = logFolderPath; }
        static void setHomeViewFilePath(const QString& homeViewFilePath) { _homeViewFilePath = homeViewFilePath; }
        static void setColorsFilePath(const QString& colorsFilePath) { _colorsFilePath = colorsFilePath; }
        static void setGroupsFolderPath(const QString& groupsFolderPart) { _groupsFolderPath = groupsFolderPart; }

    private:
        static QString _charactersFolderPath;
        static QString _avatarsFolderPath;
        static QString _relatedRelationshipsFilePath;
        static QString _logFolderPath;
        static QString _homeViewFilePath;
        static QString _colorsFilePath;
        static QString _groupsFolderPath;
    };
}
