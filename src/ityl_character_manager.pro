QT += quick widgets quickcontrols2
CONFIG += c++17 warn_on

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
        dataModel/character/character.cpp \
        dataModel/character/skill/skill.cpp \
        dataModel/homeView/home_category.cpp \
        dataModel/homeView/home_view.cpp \
        main.cpp \
        q_custom_gui_application.cpp \
        qml_types_factory.cpp \
        reader/character_reader.cpp \
        reader/home_view_reader.cpp \
        reader/json_reader_helpers.cpp \
        reader/settings_reader.cpp \
        services/relationship_validator_service.cpp \
        uiModel/character/character_ui_model.cpp \
        uiModel/character/characters_ui_collection.cpp \
        uiModel/character/characters_ui_manager.cpp \
        uiModel/character/relationship_ui_model.cpp \
        uiModel/character/skill_ui_model.cpp \
        uiModel/homeView/home_category_ui_model.cpp \
        uiModel/homeView/home_view_ui_model.cpp \
        uiModel/settings_ui_manager.cpp

RESOURCES += \
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

install_mock.path = $${OUT_PWD}
install_mock.files += $${PWD}/mock/

INSTALLS += \
    install_it \
    install_mock

DISTFILES += \
    mock/characters/character1.json \
    mock/characters/character2.json \
    mock/characters/character3.json \
    mock/colors.json \
    mock/home_view.json \
    mock/images/avatar.png \
    mock/related_relationships.json \
    qtquickcontrols2.conf \
    settings/app_config.json \
    ui/AffiliationsView.qml \
    ui/AvatarView.qml \
    ui/CharacterListView.qml \
    ui/CharacterView.qml \
    ui/DescriptionView.qml \
    ui/HomeCategoryView.qml \
    ui/HomeView.qml \
    ui/IdentityView.qml \
    ui/LinkButton.qml \
    ui/RelationshipsView.qml \
    ui/TabBarComponent.qml \
    ui/ValidationsViewer.qml \
    ui/main.qml

HEADERS += \
    characters_provider.h \
    converters/converters.h \
    dataModel/app_config.h \
    dataModel/character/character.h \
    dataModel/character/relationship.h \
    dataModel/character/skill/skill.h \
    dataModel/character/status.h \
    dataModel/homeView/home_category.h \
    dataModel/homeView/home_element_type.h \
    dataModel/homeView/home_view.h \
    q_custom_gui_application.h \
    qml_types_factory.h \
    reader/character_reader.h \
    reader/home_view_reader.h \
    reader/json_reader_helpers.h \
    reader/settings_reader.h \
    services/relationship_validator_service.h \
    uiModel/character/character_ui_model.h \
    uiModel/character/characters_ui_collection.h \
    uiModel/character/characters_ui_manager.h \
    uiModel/character/filtering_type.h \
    uiModel/character/relationship_ui_model.h \
    uiModel/character/skill_ui_model.h \
    uiModel/homeView/home_category_ui_model.h \
    uiModel/homeView/home_view_ui_model.h \
    uiModel/settings_ui_manager.h
