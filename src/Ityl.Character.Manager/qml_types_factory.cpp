#include "qml_types_factory.h"

#include <QQmlApplicationEngine>
#include <QMetaType>

#include <reader/character_reader.h>
#include <uiModels/character/character_ui_model.h>
#include <uiModels/character/characters_ui_collection.h>
#include <uiModels/group/group_ui_model.h>
#include <uiModels/homeView/home_category_ui_model.h>

namespace Ityl
{
    void QmlTypesFactory::registerTypes()
    {
        qRegisterMetaType<Ui::UiModels::CharactersUiCollection*>("CharactersUiCollection*");
        qRegisterMetaType<Ui::UiModels::HomeCategoryUiModel*>("HomeCategoryUiModel*");
        qRegisterMetaType<Ui::UiModels::GroupUiModel*>("GroupUiModel*");

        qmlRegisterType<Ui::UiModels::GroupUiModel>("Ityl", 1, 0, "GroupUiView");
    }
}
