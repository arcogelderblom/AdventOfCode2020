include_directories(${PROJECT_SOURCE_DIR}/Common/include include)

add_library(DaySixLib src/FormsProcessor)

add_executable(DaySix src/main)
target_link_libraries(DaySix Common DaySixLib)

add_executable(DaySixTest src/test)
target_link_libraries(DaySixTest DaySixLib)