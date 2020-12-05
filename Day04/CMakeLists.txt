include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayFourLib src/PassportValidator src/Passport)

add_executable(DayFour src/main)
target_link_libraries(DayFour Common DayFourLib)

add_executable(DayFourTest src/test)
target_link_libraries(DayFourTest DayFourLib)