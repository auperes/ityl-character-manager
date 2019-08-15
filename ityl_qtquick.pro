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
        src/characters_provider.cpp \
        src/converters/converters.cpp \
        src/dataModel/character.cpp \
        src/dataModel/skill/skill.cpp \
        src/main.cpp \
        src/model/character_model.cpp \
        src/model/qObjectWrapper/characters_wrapper.cpp \
        src/model/qObjectWrapper/relationships_wrapper.cpp \
        src/model/qObjectWrapper/skills_wrapper.cpp \
        src/model/relationship_model.cpp \
        src/model/skill_model.cpp \
        src/qml_types_factory.cpp \
        src/reader/character_reader.cpp \
        src/uiModel/character_ui_model.cpp \
        src/uiModel/characters_ui_collection.cpp \
        src/uiModel/relationship_ui_model.cpp \
        src/uiModel/skill_ui_model.cpp

RESOURCES += src/ui/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qtquickcontrols2.conf

HEADERS += \
    src/characters_provider.h \
    src/converters/converters.h \
    src/dataModel/character.h \
    src/dataModel/relationship.h \
    src/dataModel/skill/skill.h \
    src/model/character_model.h \
    src/model/qObjectWrapper/characters_wrapper.h \
    src/model/qObjectWrapper/relationships_wrapper.h \
    src/model/qObjectWrapper/skills_wrapper.h \
    src/model/relationship_model.h \
    src/model/skill_model.h \
    src/qml_types_factory.h \
    src/reader/character_reader.h \
    src/uiModel/character_ui_model.h \
    src/uiModel/characters_ui_collection.h \
    src/uiModel/relationship_ui_model.h \
    src/uiModel/skill_ui_model.h
