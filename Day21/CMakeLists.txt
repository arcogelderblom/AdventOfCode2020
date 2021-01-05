include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwentyOneLib src/Product src/GroceryList)

add_executable(DayTwentyOne src/main)
target_link_libraries(DayTwentyOne Common DayTwentyOneLib)
