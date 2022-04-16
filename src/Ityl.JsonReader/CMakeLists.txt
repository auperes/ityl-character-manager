set(SOURCES
    reader/character_reader.cpp
    reader/group_reader.cpp
    reader/home_view_reader.cpp
    reader/json_reader_helpers.cpp
    reader/settings_reader.cpp)

set(HEADERS
    reader/character_reader.h
    reader/group_reader.h
    reader/home_view_reader.h
    reader/json_reader_helpers.h
    reader/settings_reader.h)

add_library(Ityl.JsonReader SHARED ${SOURCES} ${HEADERS})

target_include_directories(
    Ityl.JsonReader
    PUBLIC reader/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.JsonReader
    PRIVATE Ityl.DataModel
    PRIVATE Qt6::Core)
