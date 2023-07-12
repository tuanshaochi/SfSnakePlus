cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
project(sfSnakePlus)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(main ${SOURCES}  )
target_include_directories(main PUBLIC src) 
target_link_libraries(main PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)


file(COPY "assets" DESTINATION "${CMAKE_BINARY_DIR}/${NAME}")

