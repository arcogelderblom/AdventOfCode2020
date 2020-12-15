include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayFourteenLib src/Decoder)

add_executable(DayFourteen src/main)
target_link_libraries(DayFourteen Common DayFourteenLib)
