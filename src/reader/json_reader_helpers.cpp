#include "json_reader_helpers.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Ityl::Reader
{

    QJsonObject JsonReaderHelpers::readJsonFile(const QString &filepath)
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

    QMap<QString, QString> JsonReaderHelpers::readNationsColor(const QString& filepath)
    {
        QMap<QString, QString> nationColors;
        QJsonObject jsonObject = JsonReaderHelpers::readJsonFile(filepath);
        QJsonArray nations = jsonObject["nations"].toArray();

        for (auto nation : nations)
        {
            auto nationObject = nation.toObject();
            nationColors.insert(nationObject["name"].toString(), nationObject["color"].toString());
        }

        return nationColors;
    }

}
