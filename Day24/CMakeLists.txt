include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwentyFourLib src/Floor src/HexTile)

add_executable(DayTwentyFour src/main)
target_link_libraries(DayTwentyFour Common DayTwentyFourLib)
