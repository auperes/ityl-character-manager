set(SOURCES
    adapter/character_adapter.h adapter/character_adapter.cpp

    model/json_model_mapper.h model/json_model_mapper.cpp
    model/character_dto.h model/character_dto.cpp
    model/skill_dto.h model/skill_dto.cpp
    model/relationship_dto.h model/relationship_dto.cpp
    model/group_dto.h model/group_dto.cpp
    model/avatar_dto.h model/avatar_dto.cpp

    provider/json_character_provider.h provider/json_character_provider.cpp
    provider/json_item_provider.h provider/json_item_provider.cpp
)

add_library(Ityl.Json SHARED ${SOURCES})

target_include_directories(
    Ityl.Json
    PUBLIC model/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.Json
    PRIVATE Ityl.Core
    PRIVATE Qt6::Core)
