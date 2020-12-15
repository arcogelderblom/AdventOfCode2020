include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DaySevenLib src/LuggageProcessor src/Bag)

add_executable(DaySeven src/main)
target_link_libraries(DaySeven Common DaySevenLib)

add_executable(DaySevenTest src/test)
target_link_libraries(DaySevenTest DaySevenLib)