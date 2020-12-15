include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayEightLib src/GameConsole)

add_executable(DayEight src/main)
target_link_libraries(DayEight Common DayEightLib)