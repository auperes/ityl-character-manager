set(SOURCES
    json_character_provider_tests.h json_character_provider_tests.cpp
    character_dto_tests.h character_dto_tests.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(Ityl.Json.UnitTests ${SOURCES})
add_test(NAME Ityl.Json.UnitTests COMMAND Ityl.Json.UnitTests)

#set_target_properties(Ityl.Json.UnitTests PROPERTIES
#    WIN32_EXECUTABLE TRUE
#)

target_include_directories(
    Ityl.Json.UnitTests
    PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
    Ityl.Json.UnitTests
    PRIVATE Ityl.Core
    PRIVATE Ityl.Json
    PRIVATE Qt6::Core
    PRIVATE Qt6::Test)

add_custom_command(
    TARGET Ityl.Json.UnitTests
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/UnitTests/Ityl.Json.UnitTests/testFiles/
            ${CMAKE_CURRENT_BINARY_DIR}/testFiles/)
