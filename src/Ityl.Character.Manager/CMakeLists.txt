set(SOURCES
    main.cpp
    q_custom_gui_application.cpp
    qml_types_factory.cpp
    converters/converters.cpp
    converters/ui_model_converters.cpp
    uiModels/character/character_ui_model.cpp
    uiModels/character/characters_ui_collection.cpp
    uiModels/character/characters_ui_manager.cpp
    uiModels/character/relationship_ui_model.cpp
    uiModels/character/skill_ui_model.cpp
    uiModels/group/group_info_ui_model.cpp
    uiModels/group/group_part_ui_model.cpp
    uiModels/group/group_ui_model.cpp
    uiModels/group/groups_ui_manager.cpp
    uiModels/homeView/home_category_ui_model.cpp
    uiModels/homeView/home_view_ui_model.cpp
    uiModels/settings_ui_manager.cpp)

set(HEADERS
    q_custom_gui_application.h
    qml_types_factory.h
    converters/converters.h
    converters/ui_model_converters.h
    models/character/filtering_data.h
    models/character/filtering_type.h
    models/character/grouped_ui_characters.h
    uiModels/character/character_ui_model.h
    uiModels/character/characters_ui_collection.h
    uiModels/character/characters_ui_manager.h
    uiModels/character/relationship_ui_model.h
    uiModels/character/skill_ui_model.h
    uiModels/group/group_info_ui_model.h
    uiModels/group/group_part_ui_model.h
    uiModels/group/group_ui_model.h
    uiModels/group/groups_ui_manager.h
    uiModels/homeView/home_category_ui_model.h
    uiModels/homeView/home_view_ui_model.h
    uiModels/settings_ui_manager.h)

qt5_add_resources(APP_RESOURCES ${CMAKE_CURRENT_LIST_DIR}/qml.qrc)

add_executable(Ityl.Character.Manager ${SOURCES} ${HEADERS} ${APP_RESOURCES})

target_include_directories(Ityl.Character.Manager
                           PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(
    Ityl.Character.Manager
    PRIVATE Ityl.DataModel
    PRIVATE Ityl.JsonReader
    PRIVATE Ityl.Business
    Qt5::Widgets Qt5::Qml Qt5::Quick)

add_custom_command(
    TARGET Ityl.Character.Manager
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Ityl.Character.Manager/settings/
            ${CMAKE_CURRENT_BINARY_DIR}/settings/)

add_custom_command(
    TARGET Ityl.Character.Manager
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/mock/
            ${CMAKE_CURRENT_BINARY_DIR}/mock/)
