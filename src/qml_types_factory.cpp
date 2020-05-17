#include "qml_types_factory.h"

#include <QQmlApplicationEngine>
#include <QMetaType>

#include "reader/character_reader.h"
#include "uiModel/character/character_ui_model.h"
#include "uiModel/character/characters_ui_collection.h"
#include "uiModel/group/group_ui_model.h"
#include "uiModel/homeView/home_category_ui_model.h"

namespace Ityl
{
    void QmlTypesFactory::registerTypes()
    {
        qRegisterMetaType<UiModel::CharactersUiCollection*>("CharactersUiCollection*");
        qRegisterMetaType<UiModel::HomeCategoryUiModel*>("HomeCategoryUiModel*");
        qRegisterMetaType<UiModel::GroupUiModel*>("GroupUiModel*");

        qmlRegisterType<UiModel::GroupUiModel>("Ityl", 1, 0, "GroupUiView");
    }
}
