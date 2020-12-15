include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwelveLib src/NavigationComputer)

add_executable(DayTwelve src/main)
target_link_libraries(DayTwelve Common DayTwelveLib)

add_executable(DayTwelveTest src/test)
target_link_libraries(DayTwelveTest Common DayTwelveLib)
