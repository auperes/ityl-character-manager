set(SOURCES
    back_api/character_provider.h

    front_api/character_api.h

    model/character.h model/character.cpp
    model/group.h model/group.cpp
    model/group_info.h model/group_info.cpp
    model/group_part.h model/group_part.cpp
    model/group_type.h
    model/relationship.h
    model/skill.h model/skill.cpp
    model/status.h

    service/character_service.h service/character_service.cpp
)

add_library(Ityl.Core SHARED ${SOURCES})

target_include_directories(
    Ityl.Core
    PUBLIC back_api/
    PUBLIC front_api/
    PUBLIC model/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.Core)
