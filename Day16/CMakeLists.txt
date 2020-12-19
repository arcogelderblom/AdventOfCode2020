include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DaySixteenLib src/TicketProcessor)

add_executable(DaySixteen src/main)
target_link_libraries(DaySixteen Common DaySixteenLib)
