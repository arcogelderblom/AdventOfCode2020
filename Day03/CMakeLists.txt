include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayThreeLib src/TobogganRide)

add_executable(DayThree src/main)
target_link_libraries(DayThree Common DayThreeLib)