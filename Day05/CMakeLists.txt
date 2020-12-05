include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayFiveLib src/BoardingPassScanner)

add_executable(DayFive src/main)
target_link_libraries(DayFive Common DayFiveLib)

add_executable(DayFiveTest src/test)
target_link_libraries(DayFiveTest DayFiveLib)