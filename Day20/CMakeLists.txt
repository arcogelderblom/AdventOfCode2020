include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwentyLib src/ImageTile src/ImageAssembler src/ImageProcessor)

add_executable(DayTwenty src/main)
target_link_libraries(DayTwenty Common DayTwentyLib)
