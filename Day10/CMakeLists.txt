include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayTenLib src/AdapterStacker)

add_executable(DayTen src/main)
target_link_libraries(DayTen Common DayTenLib)

add_executable(DayTenTest src/test)
target_link_libraries(DayTenTest Common DayTenLib)