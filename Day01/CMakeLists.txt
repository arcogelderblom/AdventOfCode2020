include_directories(${PROJECT_SOURCE_DIR}/Common/include)

add_executable(DayOne src/main)
target_link_libraries(DayOne Common)