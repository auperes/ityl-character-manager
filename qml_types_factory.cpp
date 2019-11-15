#include "qml_types_factory.h"

#include <QQmlApplicationEngine>
#include <QMetaType>

#include "reader/character_reader.h"
#include "uiModel/character_ui_model.h"
#include "uiModel/characters_ui_collection.h"

void QmlTypesFactory::registerTypes()
{
    qmlRegisterType<CharactersUiCollection>("Character", 1, 0, "CharactersUiCollection");
    qmlRegisterUncreatableType<CharacterUiModel>("Character", 1, 0, "CharacterUiModel",
        QStringLiteral("CharacterUiModel should not be created in QML"));
}
