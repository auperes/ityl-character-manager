#include "character.h"

namespace Ityl::Core
{
    const std::string& Character::getFirstName() const
    {
        return _firstName;
    }

    Character& Character::setFirstName(const std::string& firstName)
    {
        _firstName = firstName;
        return *this;
    }

    const std::string& Character::getLastName() const
    {
        return _lastName;
    }

    Character& Character::setLastName(const std::string& lastName)
    {
        _lastName = lastName;
        return *this;
    }

    const std::string& Character::getBirthName() const
    {
        return _birthName;
    }

    Character& Character::setBirthName(const std::string& birthName)
    {
        _birthName = birthName;
        return *this;
    }

    const std::string& Character::getNickName() const
    {
        return _nickName;
    }

    Character& Character::setNickName(const std::string& nickName)
    {
        _nickName = nickName;
        return *this;
    }

    const std::string& Character::getTitle() const
    {
        return _title;
    }

    Character& Character::setTitle(const std::string& title)
    {
        _title = title;
        return *this;
    }

    const std::string& Character::getQuote() const
    {
        return _quote;
    }

    Character& Character::setQuote(const std::string& quote)
    {
        _quote = quote;
        return *this;
    }

    const std::string& Character::getBirthPlace() const
    {
        return _birthPlace;
    }

    Character& Character::setBirthPlace(const std::string& birthPlace)
    {
        _birthPlace = birthPlace;
        return *this;
    }

    const std::string& Character::getLivelyPlace() const
    {
        return _livelyPlace;
    }

    Character& Character::setLivelyPlace(const std::string& livelyPlace)
    {
        _livelyPlace = livelyPlace;
        return *this;
    }

    const std::string& Character::getBirthNation() const
    {
        return _birthNation;
    }

    Character& Character::setBirthNation(const std::string& birthNation)
    {
        _birthNation = birthNation;
        return *this;
    }

    const std::string& Character::getCurrentNation() const
    {
        return _currentNation;
    }

    Character& Character::setCurrentNation(const std::string& currentNation)
    {
        _currentNation = currentNation;
        return *this;
    }

    Status Character::getStatus() const
    {
        return _status;
    }

    Character& Character::setStatus(Status status)
    {
        _status = status;
        return *this;
    }

    const std::vector<std::string>& Character::getRoles() const
    {
        return _roles;
    }

    Character& Character::setRoles(const std::vector<std::string>& roles)
    {
        _roles = roles;
        return *this;
    }

    const std::unordered_map<std::string, std::vector<Skill> >& Character::getSkills() const
    {
        return _skills;
    }

    Character& Character::setSkills(const std::unordered_map<std::string, std::vector<Skill> >& skills)
    {
        _skills = skills;
        return *this;
    }

    const std::unordered_map<Relationship, std::vector<std::pair<std::string, std::string> > >& Character::getRelationships() const
    {
        return _relationships;
    }

    Character& Character::setRelationships(const std::unordered_map<Relationship, std::vector<std::pair<std::string, std::string> > >& relationships)
    {
        _relationships = relationships;
        return *this;
    }

    const std::vector<GroupInfo>& Character::getEthnies() const
    {
        return _ethnies;
    }

    Character& Character::setEthnies(const std::vector<GroupInfo>& ethnies)
    {
        _ethnies = ethnies;
        return *this;
    }

    const std::vector<GroupInfo>& Character::getGroups() const
    {
        return _groups;
    }

    Character& Character::setGroups(const std::vector<GroupInfo>& groups)
    {
        _groups = groups;
        return *this;
    }

    const std::vector<std::string>& Character::getAvatars() const
    {
        return _avatars;
    }

    Character& Character::setAvatars(const std::vector<std::string>& avatars)
    {
        _avatars = avatars;
        return *this;
    }

    const std::string& Character::getMiniAvatar() const
    {
        return _miniAvatar;
    }

    Character& Character::setMiniAvatar(const std::string& miniAvatar)
    {
        _miniAvatar = miniAvatar;
        return *this;
    }

    const std::string& Character::getDescription() const
    {
        return _description;
    }

    Character& Character::setDescription(const std::string& description)
    {
        _description = description;
        return *this;
    }
}
