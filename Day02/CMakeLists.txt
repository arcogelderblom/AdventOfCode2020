include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTwoLib src/PasswordValidator)

add_executable(DayTwo src/main)
target_link_libraries(DayTwo Common DayTwoLib)

add_executable(DayTwoTest src/test)
target_link_libraries(DayTwoTest DayTwoLib)