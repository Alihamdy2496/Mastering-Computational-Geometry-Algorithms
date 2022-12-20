add_library(vector vector.cpp)

target_link_libraries(vector core)

target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
