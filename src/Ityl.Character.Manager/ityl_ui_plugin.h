#pragma once

#include <QtQml/QQmlExtensionPlugin>

class ItylUiPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "itylui/1.0")
public:
    void registerTypes(const char* uri) override;
};
