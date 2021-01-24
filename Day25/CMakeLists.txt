include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwentyFiveLib src/Crypto)

add_executable(DayTwentyFive src/main)
target_link_libraries(DayTwentyFive Common DayTwentyFiveLib)
