#include "json_character_provider_tests.h"

#include <sstream>
#include <QtTest/QTest>

namespace Ityl::Json
{
    const std::string JsonCharacterProviderTests::firstName = "firstName";
    const std::string JsonCharacterProviderTests::lastName = "lastName";
    const std::string JsonCharacterProviderTests::birthName = "birthName";
    const std::string JsonCharacterProviderTests::nickName = "nickName";
    const std::string JsonCharacterProviderTests::title = "title";
    const std::string JsonCharacterProviderTests::quote = "quote";
    const std::string JsonCharacterProviderTests::birthPlace = "birthPlace";
    const std::string JsonCharacterProviderTests::livelyPlace = "livelyPlace";
    const std::string JsonCharacterProviderTests::birthNation = "birthNation";
    const std::string JsonCharacterProviderTests::currentNation = "currentNation";
    const std::string JsonCharacterProviderTests::birthDate = "birthDate";
    const std::string JsonCharacterProviderTests::deathDate = "deathDate";
    const std::string JsonCharacterProviderTests::description = "description";

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

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveFirstName()
    {
        auto character = _characterProvider->loadCharacter(firstName, "lastName");
        QCOMPARE(character.getFirstName(), firstName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveLastName()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getLastName(), lastName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthName()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getBirthName(), birthName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveNickName()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getNickName(), nickName);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveTitle()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getTitle(), title);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveQuote()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getQuote(), quote);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthPlace()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getBirthPlace(), birthPlace);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveLivelyPlace()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getLivelyPlace(), livelyPlace);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthNation()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getBirthNation(), birthNation);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveCurrentNation()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getCurrentNation(), currentNation);
    }

//    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveBirthDate()
//    {
//        auto character = _characterProvider->loadCharacter(firstName, lastName);
//        QCOMPARE(character.getBirthDate(), birthDate);
//    }

//    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveDeathDate()
//    {
//        auto character = _characterProvider->loadCharacter(firstName, lastName);
//        QCOMPARE(character.getDeathDate(), deathDate);
//    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveStatus()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getStatus(), Core::Status::Alive);
    }

    void JsonCharacterProviderTests::LoadCharacter_ShouldHaveDescription()
    {
        auto character = _characterProvider->loadCharacter(firstName, lastName);
        QCOMPARE(character.getDescription(), description);
    }
}

QTEST_MAIN(Ityl::Json::JsonCharacterProviderTests)
#include "json_character_provider_tests.moc"
