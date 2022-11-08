#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "group_info.h"
#include "relationship.h"
#include "skill.h"
#include "status.h"

namespace Ityl::Core
{
    class Character
    {
    public:
        Character() = default;

        Status getStatus() const;
        const std::string& getBirthName() const;
        const std::string& getBirthNation() const;
        const std::string& getBirthPlace() const;
        const std::string& getCurrentNation() const;
        const std::string& getDescription() const;
        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const std::string& getLivelyPlace() const;
        const std::string& getMiniAvatar() const;
        const std::string& getNickName() const;
        const std::string& getQuote() const;
        const std::string& getTitle() const;
        const std::unordered_map<Relationship, std::vector<std::pair<std::string, std::string> > >& getRelationships() const;
        const std::unordered_map<std::string, std::vector<Skill> >& getSkills() const;
        const std::vector<GroupInfo>& getEthnies() const;
        const std::vector<GroupInfo>& getGroups() const;
        const std::vector<std::string>& getAvatars() const;
        const std::vector<std::string>& getRoles() const;

        Character& setAvatars(const std::vector<std::string>& avatars);
        Character& setBirthName(const std::string& birthName);
        Character& setBirthNation(const std::string& birthNation);
        Character& setBirthPlace(const std::string& birthPlace);
        Character& setCurrentNation(const std::string& currentNation);
        Character& setDescription(const std::string& description);
        Character& setEthnies(const std::vector<GroupInfo>& ethnies);
        Character& setFirstName(const std::string& firstName);
        Character& setGroups(const std::vector<GroupInfo>& groups);
        Character& setLastName(const std::string& lastName);
        Character& setLivelyPlace(const std::string& livelyPlace);
        Character& setMiniAvatar(const std::string& miniAvatar);
        Character& setNickName(const std::string& nickName);
        Character& setQuote(const std::string& quote);
        Character& setRelationships(const std::unordered_map<Relationship, std::vector<std::pair<std::string, std::string> > >& relationships);
        Character& setRoles(const std::vector<std::string>& roles);
        Character& setSkills(const std::unordered_map<std::string, std::vector<Skill> >& skills);
        Character& setStatus(Status status);
        Character& setTitle(const std::string& title);

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _birthName;
        std::string _nickName;
        std::string _title;
        std::string _quote;
        std::string _birthPlace;
        std::string _livelyPlace;
        std::string _birthNation;
        std::string _currentNation;
        Status _status;

        std::vector<std::string> _roles;
        std::unordered_map<std::string, std::vector<Skill>> _skills;
        std::unordered_map<Relationship, std::vector<std::pair<std::string, std::string>>> _relationships;
        std::vector<GroupInfo> _ethnies;
        std::vector<GroupInfo> _groups;
        std::vector<std::string> _avatars;
        std::string _miniAvatar;

        std::string _description;
    };
}
