include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayEighteenLib src/Calculator)

add_executable(DayEighteen src/main)
target_link_libraries(DayEighteen Common DayEighteenLib)
