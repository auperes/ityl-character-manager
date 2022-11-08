set(SOURCES
    model/character/character_ui_model.h model/character/character_ui_model.cpp
    model/character/relationship_ui_model.h model/character/relationship_ui_model.cpp
    model/character/skill_ui_model.h model/character/skill_ui_model.cpp
    model/group/group_info_ui_model.h model/group/group_info_ui_model.cpp
)

add_library(Ityl.UI SHARED ${SOURCES})

target_include_directories(
    Ityl.UI
    PUBLIC model/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.UI
    PRIVATE Qt6::Core)
