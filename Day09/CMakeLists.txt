include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DayNineLib src/XMASEncryptor)

add_executable(DayNine src/main)
target_link_libraries(DayNine Common DayNineLib)