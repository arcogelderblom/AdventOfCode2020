include_directories(include)

add_library(DayFifteenLib src/MemoryGame)

add_executable(DayFifteen src/main)
target_link_libraries(DayFifteen DayFifteenLib)
