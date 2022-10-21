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

      void LoadCharacter_ShouldHaveFirstName() const;
      void LoadCharacter_ShouldHaveLastName() const;
      void LoadCharacter_ShouldHaveBirthName() const;
      void LoadCharacter_ShouldHaveNickName() const;
      void LoadCharacter_ShouldHaveTitle() const;
      void LoadCharacter_ShouldHaveQuote() const;
      void LoadCharacter_ShouldHaveBirthPlace() const;
      void LoadCharacter_ShouldHaveLivelyPlace() const;
      void LoadCharacter_ShouldHaveBirthNation() const;
      void LoadCharacter_ShouldHaveCurrentNation() const;
//      void LoadCharacter_ShouldHaveBirthDate() const;
//      void LoadCharacter_ShouldHaveDeathDate() const;
      void LoadCharacter_ShouldHaveStatus() const;
      void LoadCharacter_ShouldHaveDescription() const;
      void LoadCharacter_ShouldHaveRoles() const;
      void LoadCharacter_ShouldHaveSkills() const;
//      void LoadCharacter_ShouldHaveRelationships() const;
      void LoadCharacter_ShouldHaveEthnies() const;
      void LoadCharacter_ShouldHaveGroups() const;
      void LoadCharacter_ShouldHaveAvatars() const;

    private:
      static const std::string firstName;
      static const std::string lastName;

      std::unique_ptr<Ityl::Json::JsonCharacterProvider> _characterProvider;

      bool CompareSkill(const Core::Skill& actualSkill, const Core::Skill& expectedSkill) const;
    };
}
