include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayElevenLib src/FloorPlan)

add_executable(DayEleven src/main)
target_link_libraries(DayEleven Common DayElevenLib)

add_executable(DayElevenTest src/test)
target_link_libraries(DayElevenTest Common DayElevenLib)
