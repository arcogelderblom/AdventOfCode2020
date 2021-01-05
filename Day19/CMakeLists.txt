include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayNineteenLib src/MessageProcessor)

add_executable(DayNineteen src/main)
target_link_libraries(DayNineteen Common DayNineteenLib)
