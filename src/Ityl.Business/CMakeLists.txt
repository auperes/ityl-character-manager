set(SOURCES
    providers/characters_provider.cpp
    providers/groups_provider.cpp
    services/relationship_validator_service.cpp)

set(HEADERS
    models/grouped_characters.h
    providers/characters_provider.h
    providers/groups_provider.h
    services/relationship_validator_service.h)

add_library(Ityl.Business SHARED ${SOURCES} ${HEADERS})

target_include_directories(
    Ityl.Business
    PUBLIC models/
    PUBLIC providers/
    PUBLIC services/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.Business
    PRIVATE Ityl.DataModel
    PRIVATE Ityl.JsonReader
    PRIVATE Qt5::Core)
