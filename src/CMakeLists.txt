cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ItylCharacterManager VERSION 1.0
                             LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(CMAKE_VERSION VERSION_LESS 3.7.0)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Qml Quick QuickControls2 REQUIRED)

set(SOURCES converters/converters.cpp
            dataModel/character/skill/skill.cpp
            dataModel/character/character.cpp
            dataModel/group/group.cpp
            dataModel/group/group_info.cpp
            dataModel/group/group_part.cpp
            dataModel/homeView/home_category.cpp
            dataModel/homeView/home_view.cpp
            dataModel/app_config.cpp
            provider/characters_provider.cpp
            provider/groups_provider.cpp
            reader/character_reader.cpp
            reader/group_reader.cpp
            reader/home_view_reader.cpp
            reader/json_reader_helpers.cpp
            reader/settings_reader.cpp
            services/relationship_validator_service.cpp
            uiModel/character/character_ui_model.cpp
            uiModel/character/characters_ui_collection.cpp
            uiModel/character/characters_ui_manager.cpp
            uiModel/character/relationship_ui_model.cpp
            uiModel/character/skill_ui_model.cpp
            uiModel/group/group_info_ui_model.cpp
            uiModel/group/group_part_ui_model.cpp
            uiModel/group/group_ui_model.cpp
            uiModel/group/groups_ui_manager.cpp
            uiModel/homeView/home_category_ui_model.cpp
            uiModel/homeView/home_view_ui_model.cpp
            uiModel/settings_ui_manager.cpp
            q_custom_gui_application.cpp
            qml_types_factory.cpp)

if(CMAKE_VERSION VERSION_LESS 3.12.0)
    add_definitions(-DQT_DEPRECATED_WARNINGS)
else()
    add_compile_definitions(QT_DEPRECATED_WARNINGS)
endif()

add_executable(ityl_character_manager
    ${SOURCES}
    main.cpp
    qml.qrc)

target_link_libraries(ityl_character_manager Qt5::Widgets Qt5::Qml Qt5::Quick)

add_custom_command(TARGET ityl_character_manager POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/settings/ ${CMAKE_CURRENT_BINARY_DIR}/settings/)

add_custom_command(TARGET ityl_character_manager POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/mock/ ${CMAKE_CURRENT_BINARY_DIR}/mock/)
