#include "ityl_ui_plugin.h"

#include <QtQml/QtQml>

#include "uiModels/group/group_ui_model.h"

void ItylUiPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<Ityl::Ui::UiModels::GroupUiModel>(uri, 1, 0, "GroupUiView");
}
