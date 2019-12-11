#include "relationship_validator_service.h"

#include <iostream>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>
#include <QTextStream>

#include "../converters/converters.h"
#include "../dataModel/app_config.h"

RelationshipValidatorService::RelationshipValidatorService()
{
    QString content;
    QFile file;
    file.setFileName(AppConfig::getRelatedRelationshipsFilePath());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    content = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(content.toUtf8());
    QJsonObject jsonObject = document.object();

    QJsonArray relationshipsArray = jsonObject["relatedRelationships"].toArray();

    for (auto value : relationshipsArray)
    {
        QJsonObject object = value.toObject();
        Relationship link = Converters::convertRelationshipToEnum(object["link"].toString());
        Relationship relatesTo = Converters::convertRelationshipToEnum(object["relatesTo"].toString());
        _relatedRelationships.emplace(link, relatesTo);
    }
}

void RelationshipValidatorService::addCharacterName(QString characterName)
{
    _charactersNames.insert(characterName);
}

void RelationshipValidatorService::addRelationship(QString characterName, Relationship relationship, QString relatedCharacterName)
{
    // init all needed data
    auto relatedRelationshipIterator = _relatedRelationships.find(relationship);
    if (relatedRelationshipIterator == _relatedRelationships.end())
    {
        std::cout << "Unable to find relationship " << Converters::convertRelationshipSingularForm(relationship).toStdString() << " in related relationships table." << std::endl;
        return;
    }

    auto characterNameStr = characterName.toStdString();
    auto relatedCharacterNameStr = relatedCharacterName.toStdString();
    Relationship relatedRelationship = relatedRelationshipIterator->second;

    // find relationship
    auto missingRelationshipIterator = _missingRelationships.find(characterNameStr);
    if (missingRelationshipIterator != _missingRelationships.end())
    {
        auto [itBegin, itEnd] = missingRelationshipIterator->second.equal_range(relatedCharacterNameStr);
        if (itBegin != missingRelationshipIterator->second.end())
        {
            auto it = itBegin;
            while (it != itEnd)
            {
                if (it->second == relationship)
                {
                    missingRelationshipIterator->second.erase(it);
                    if (missingRelationshipIterator->second.empty())
                        _missingRelationships.erase(missingRelationshipIterator);
                    return;
                }
                ++it;
            }
        }
    }

    _missingRelationships[relatedCharacterNameStr].emplace(characterNameStr, relatedRelationship);
}

void RelationshipValidatorService::logMissingRelationships()
{
    QFile missingRelationshipsFile;
    missingRelationshipsFile.setFileName(AppConfig::getLogFolderPath() + "missingRelationships.log");
    missingRelationshipsFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QFile missingCharactersFile;
    missingCharactersFile.setFileName(AppConfig::getLogFolderPath() + "missingCharacters.log");
    missingCharactersFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream outMissingRelationships(&missingRelationshipsFile);
    outMissingRelationships.setCodec("UTF-8");
    QTextStream outMissingCharacters(&missingCharactersFile);
    outMissingCharacters.setCodec("UTF-8");

    for (auto& element : _missingRelationships)
    {
        auto it = _charactersNames.find(QString::fromStdString(element.first));
        if (it != _charactersNames.end())
        {
            outMissingRelationships << QString::fromStdString(element.first) << " " << element.second.size() << "\n";
            for (const auto& relation : element.second)
            {
                outMissingRelationships << "- " << QString::fromStdString(relation.first) << " : " << Converters::convertRelationshipSingularForm(relation.second) << "\n";
            }
        }
        else
        {
            outMissingCharacters << QString::fromStdString(element.first) << " " << element.second.size() << "\n";
            for (const auto& relation : element.second)
            {
                outMissingCharacters << "- " << QString::fromStdString(relation.first) << " : " << Converters::convertRelationshipSingularForm(relation.second) << "\n";
            }
        }
    }
}
