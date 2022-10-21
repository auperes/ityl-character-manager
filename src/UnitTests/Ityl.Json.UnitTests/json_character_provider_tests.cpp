#include "json_character_provider_tests.h"

#include <sstream>
#include <unordered_map>
#include <QtTest/QTest>

namespace Ityl::Json
{
    const std::string JsonCharacterProviderTests::firstName = "firstName";
    const std::string JsonCharacterProviderTests::lastName = "lastName";

    void JsonCharacterProviderTests::init()
    {
        std::stringstream fullpath;
        fullpath << QCoreApplication::applicationDirPath().toStdString() << "/" << "testFiles";
        Ityl::Json::JsonItemProvider<Ityl::Json::CharacterDto> provider(fullpath.str());
        Ityl::Json::CharacterAdapter adapter;
        _characterProvider = std::make_unique<Ityl::Json::JsonCharacterProvider>(std::move(provider), std::move(adapter));
    }

    void JsonCharacterProviderTests::cleanup()
    {
        _characterProvider = nullptr;
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveFirstName() const
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getFirstName(), firstName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveLastName() const
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getLastName(), lastName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthName() const
    {
        const std::string expectedBirthName = "birthName";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getBirthName(), expectedBirthName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveNickName() const
    {
        const std::string expectedNickName = "nickName";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getNickName(), expectedNickName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveTitle() const
    {
        const std::string expectedTitle = "title";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getTitle(), expectedTitle);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveQuote() const
    {
        const std::string expectedQuote = "quote";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getQuote(), expectedQuote);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthPlace() const
    {
        const std::string expectedBirthPlace = "birthPlace";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getBirthPlace(), expectedBirthPlace);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveLivelyPlace() const
    {
        const std::string expectedLivelyPlace = "livelyPlace";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getLivelyPlace(), expectedLivelyPlace);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthNation() const
    {
        const std::string expectedBirthNation = "birthNation";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getBirthNation(), expectedBirthNation);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveCurrentNation() const
    {
        const std::string expectedCurrentNation = "currentNation";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getCurrentNation(), expectedCurrentNation);
    }

//    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthDate()
//    {
//        const std::string expectedBirthDate = "birthDate";
//        auto character = _characterProvider->loadCharacter(firstName, lastName);
//        QCOMPARE(character.getBirthDate(), expectedBirthDate);
//    }

//    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveDeathDate()
//    {
//        const std::string expectedDeathDate = "deathDate";
//        auto character = _characterProvider->loadCharacter(firstName, lastName);
//        QCOMPARE(character.getDeathDate(), expectedDeathDate);
//    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveStatus() const
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getStatus(), Core::Status::Alive);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveDescription() const
    {
        const std::string expectedDescription = "description";
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getDescription(), expectedDescription);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveRoles() const
    {
        const std::vector<std::string> expectedRoles { "role1", "role2" };

        auto character = _characterProvider->loadCharacter(firstName, lastName);

        const auto& roles = character.getRoles();
        QCOMPARE(roles.size(), expectedRoles.size());

        unsigned i = 0;
        for (const auto& role : roles)
        {
            QCOMPARE(role, expectedRoles[i]);
            i++;
        }
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveSkills() const
    {
        std::unordered_map<std::string, std::vector<Core::Skill>> expectedSkills;
        expectedSkills.emplace("category1", std::vector<Core::Skill> { Core::Skill("skillName1") });
        expectedSkills.emplace("category2", std::vector<Core::Skill> { Core::Skill("skillName2", std::vector<std::string> { "specialty" }) });

        auto character = _characterProvider->loadCharacter(firstName, lastName);

        const auto& skills = character.getSkills();
        QCOMPARE(skills.size(), expectedSkills.size());

        QCOMPARE(CompareSkill(skills.at("category1")[0], expectedSkills.at("category1")[0]), true);
        QCOMPARE(CompareSkill(skills.at("category2")[0], expectedSkills.at("category2")[0]), true);
    }

    bool JsonCharacterProviderTests::CompareSkill(const Core::Skill& actualSkill, const Core::Skill& expectedSkill) const
    {
        if (actualSkill.getType() != expectedSkill.getType())
            return false;
        if (actualSkill.getSpecialties().size() != expectedSkill.getSpecialties().size())
            return false;

        for (auto i = 0; i < actualSkill.getSpecialties().size(); ++i)
        {
            auto actualSpecialty = actualSkill.getSpecialties()[i];
            auto expectedSpecialty = expectedSkill.getSpecialties()[i];

            if (actualSpecialty != expectedSpecialty)
                return false;
        }

        return true;
    }

//    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveRelationships() const
//    {

//    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveEthnies() const
    {
        Core::GroupInfo ethnie1("ethnie1");
        ethnie1.setType(Core::GroupType::Ethnie);

        Core::GroupInfo ethnie2("ethnie2");
        ethnie2.setType(Core::GroupType::Ethnie);

        const std::vector<Core::GroupInfo> expectedEthnies { ethnie1, ethnie2 };

        auto character = _characterProvider->loadCharacter(firstName, lastName);

        const auto& ethnies = character.getEthnies();
        QCOMPARE(ethnies.size(), expectedEthnies.size());

        unsigned i = 0;
        for (const auto& ethnie : ethnies)
        {
            QCOMPARE(ethnie.getName(), expectedEthnies[i].getName());
            QCOMPARE(ethnie.getType(), expectedEthnies[i].getType());
            QCOMPARE(ethnie.getSubgroupName(), expectedEthnies[i].getSubgroupName());
            QCOMPARE(ethnie.getRole(), expectedEthnies[i].getRole());
            QCOMPARE(ethnie.getIsOld(), expectedEthnies[i].getIsOld());
            i++;
        }
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveGroups() const
    {
        Core::GroupInfo group1("group1");
        group1.setType(Core::GroupType::Organization)
               .setRole("role1");

        Core::GroupInfo group2("group2");
        group2.setType(Core::GroupType::Group)
               .setSubgroupName("subgroup")
               .setRole("role2")
               .setIsOld(true);

        const std::vector<Core::GroupInfo> expectedGroups { group1, group2 };

        auto character = _characterProvider->loadCharacter(firstName, lastName);

        const auto& groups = character.getGroups();
        QCOMPARE(groups.size(), expectedGroups.size());

        unsigned i = 0;
        for (const auto& group : groups)
        {
            QCOMPARE(group.getName(), expectedGroups[i].getName());
            QCOMPARE(group.getType(), expectedGroups[i].getType());
            QCOMPARE(group.getSubgroupName(), expectedGroups[i].getSubgroupName());
            QCOMPARE(group.getRole(), expectedGroups[i].getRole());
            QCOMPARE(group.getIsOld(), expectedGroups[i].getIsOld());
            i++;
        }
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveAvatars() const
    {
        const std::string expectedAvatar = "avatar.png";
        const std::string expectedMiniAvatar = "miniAvatar.png";

        auto character = _characterProvider->loadCharacter(firstName, lastName);

        const auto& avatars = character.getAvatars();
        QCOMPARE(avatars.size(), 2);
        QCOMPARE(avatars[0], expectedAvatar);
        QCOMPARE(character.getMiniAvatar(), expectedMiniAvatar);
    }
}

QTEST_MAIN(Ityl::Json::JsonCharacterProviderTests)
#include "json_character_provider_tests.moc"
