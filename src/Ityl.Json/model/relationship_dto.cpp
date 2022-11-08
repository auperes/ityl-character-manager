#include "relationship_dto.h"

namespace Ityl::Json
{
    RelationshipDto::RelationshipDto()
    {
        
    }

    const QString& RelationshipDto::getType() const
    {
        return _type;
    }

    void RelationshipDto::setType(const QString& type)
    {
        _type = type;
    }

    const QString& RelationshipDto::getFirstName() const
    {
        return _firstName;
    }

    void RelationshipDto::setFirstName(const QString& firstName)
    {
        _firstName = firstName;
    }

    const QString& RelationshipDto::getLastName() const
    {
        return _lastName;
    }

    void RelationshipDto::setLastName(const QString& lastName)
    {
        _lastName = lastName;
    }

    bool RelationshipDto::getIsOld() const
    {
        return _isOld;
    }

    void RelationshipDto::setIsOld(bool isOld)
    {
        this->_isOld = isOld;
    }

    void RelationshipDto::read(const QJsonObject& json)
    {
        _type = json["link"].toString();
        _firstName = json["firstName"].toString();
        _lastName = json["lastName"].toString();
        _isOld =  json["old"].toBool();
    }

    void RelationshipDto::write(QJsonObject& json)
    {
        throw std::runtime_error("Not implemented.");
    }
}
