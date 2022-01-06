set(SOURCES
    character/skill/skill.cpp
    character/character.cpp
    config/app_config.cpp
    converters/data_model_converters.cpp
    group/group_info.cpp
    group/group_part.cpp
    group/group.cpp
    homeView/home_category.cpp
    homeView/home_view.cpp)

set(HEADERS
    character/skill/skill.h
    character/character.h
    character/relationship.h
    character/status.h
    config/app_config.h
    converters/data_model_converters.h
    group/group_info.h
    group/group_part.h
    group/group_type.h
    group/group.h
    homeView/home_category.h
    homeView/home_element_type.h
    homeView/home_view.h)

add_library(Ityl.DataModel SHARED ${SOURCES} ${HEADERS})

target_include_directories(
    Ityl.DataModel
    PUBLIC character/skill
    PUBLIC character/
    PUBLIC config/
    PUBLIC converters/
    PUBLIC group/
    PUBLIC homeView/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.DataModel
    PRIVATE Qt5::Core)
