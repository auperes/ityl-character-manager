enable_testing()

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} --coverage")
add_subdirectory(Ityl.Json.UnitTests)
