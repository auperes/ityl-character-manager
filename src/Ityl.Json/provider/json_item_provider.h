#pragma once

#include <sstream>
#include <string>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ityl::Json
{
    class JsonUtils
    {
    public:
        static const std::string JSON_EXTENSION;
        static const std::string UNDERSCORE;
        static const std::string SEPARATOR;
    };

    template<typename TItemDto>
    class JsonItemProvider
    {
    public:
        JsonItemProvider(const std::string& folderPath);

        TItemDto readItem(const std::string& filename);

    private:
        std::string _folderPath;

        QJsonObject readJsonFile(const QString& filepath);
    };

///////////////////////////
    template<typename TItemDto>
    JsonItemProvider<TItemDto>::JsonItemProvider(const std::string& folderPath)
        : _folderPath(folderPath)
    {
    }

    template<typename TItemDto>
    TItemDto JsonItemProvider<TItemDto>::readItem(const std::string& filename)
    {
        TItemDto itemDto;
        std::stringstream fullpath;
        fullpath << _folderPath << JsonUtils::SEPARATOR << filename;
        auto jsonObject = readJsonFile(QString::fromStdString(fullpath.str()));
        itemDto.read(jsonObject);
        return itemDto;
    }

    template<typename TItemDto>
    QJsonObject JsonItemProvider<TItemDto>::readJsonFile(const QString &filepath)
    {
        QString content;
        QFile file;
        file.setFileName(filepath);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        content = file.readAll();
        file.close();
        QJsonParseError error;
        QJsonDocument document = QJsonDocument::fromJson(content.toUtf8(), &error);
        if (document.isNull())
            throw std::logic_error(error.errorString().toStdString());

        return document.object();
    }
}
