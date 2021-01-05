include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwentyTwoLib src/CombatGame src/Player src/RecursiveCombatGame)

add_executable(DayTwentyTwo src/main)
target_link_libraries(DayTwentyTwo Common DayTwentyTwoLib)
