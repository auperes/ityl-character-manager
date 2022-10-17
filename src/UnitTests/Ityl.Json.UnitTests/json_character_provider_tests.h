#pragma once

#include <memory>
#include <QObject>
#include <provider/json_character_provider.h>

namespace Ityl::Json
{
    class JsonCharacterProviderTests : public QObject
    {
        Q_OBJECT

    public:
        JsonCharacterProviderTests() = default;

    private slots:
      void init();
      void cleanup();

      void LoadCharacter_ShouldHaveFirstName();
      void LoadCharacter_ShouldHaveLastName();
      void LoadCharacter_ShouldHaveBirthName();
      void LoadCharacter_ShouldHaveNickName();
      void LoadCharacter_ShouldHaveTitle();
      void LoadCharacter_ShouldHaveQuote();
      void LoadCharacter_ShouldHaveBirthPlace();
      void LoadCharacter_ShouldHaveLivelyPlace();
      void LoadCharacter_ShouldHaveBirthNation();
      void LoadCharacter_ShouldHaveCurrentNation();
//      void LoadCharacter_ShouldHaveBirthDate();
//      void LoadCharacter_ShouldHaveDeathDate();
      void LoadCharacter_ShouldHaveStatus();
      void LoadCharacter_ShouldHaveDescription();
      void LoadCharacter_ShouldHaveRoles();
//      void LoadCharacter_ShouldHaveSkills();
//      void LoadCharacter_ShouldHaveRelationships();
//      void LoadCharacter_ShouldHaveEthnies();
//      void LoadCharacter_ShouldHaveGroups();
//      void LoadCharacter_ShouldHaveAvatars();

    private:
        static const std::string firstName;
        static const std::string lastName;
        static const std::string birthName;
        static const std::string nickName;
        static const std::string title;
        static const std::string quote;
        static const std::string birthPlace;
        static const std::string livelyPlace;
        static const std::string birthNation;
        static const std::string currentNation;
        static const std::string birthDate;
        static const std::string deathDate;
        static const std::string description;

        std::unique_ptr<Ityl::Json::JsonCharacterProvider> _characterProvider;
    };
}
