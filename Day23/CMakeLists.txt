include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwentyThreeLib src/Cup src/CupGame)

add_executable(DayTwentyThree src/main)
target_link_libraries(DayTwentyThree Common DayTwentyThreeLib)
