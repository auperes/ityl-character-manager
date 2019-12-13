QT += quick widgets
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        characters_provider.cpp \
        converters/converters.cpp \
        dataModel/app_config.cpp \
        dataModel/character.cpp \
        dataModel/skill/skill.cpp \
        main.cpp \
        qml_types_factory.cpp \
        reader/character_reader.cpp \
        services/relationship_validator_service.cpp \
        uiModel/character_ui_model.cpp \
        uiModel/characters_ui_collection.cpp \
        uiModel/quick_navigation_ui_model.cpp \
        uiModel/relationship_ui_model.cpp \
        uiModel/skill_ui_model.cpp

RESOURCES += \
    qml.qrc \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

install_it.path = $${OUT_PWD}/settings
install_it.files += $${PWD}/settings/app_config.json

INSTALLS += install_it

DISTFILES += \
    .gitignore \
    qtquickcontrols2.conf \
    settings/app_config.json \
    ui/AvatarView.qml \
    ui/CharacterListView.qml \
    ui/CharacterView.qml \
    ui/IdentityView.qml \
    ui/QuickNavigation.qml \
    ui/ValidationsViewer.qml \
    ui/main.qml

HEADERS += \
    characters_provider.h \
    converters/converters.h \
    dataModel/app_config.h \
    dataModel/character.h \
    dataModel/relationship.h \
    dataModel/skill/skill.h \
    dataModel/status.h \
    qml_types_factory.h \
    reader/character_reader.h \
    services/relationship_validator_service.h \
    uiModel/character_ui_model.h \
    uiModel/characters_ui_collection.h \
    uiModel/quick_navigation_ui_model.h \
    uiModel/relationship_ui_model.h \
    uiModel/skill_ui_model.h
