include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DaySeventeenLib src/ConwayCubesV1 src/ConwayCubesV2)

add_executable(DaySeventeen src/main)
target_link_libraries(DaySeventeen Common DaySeventeenLib)

add_executable(DaySeventeenTest src/test)
target_link_libraries(DaySeventeenTest Common DaySeventeenLib)
