include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayThirteenLib src/BusPlanner)

add_executable(DayThirteen src/main)
target_link_libraries(DayThirteen Common DayThirteenLib)
