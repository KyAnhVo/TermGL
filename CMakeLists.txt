cmake_minimum_required(VERSION 3.16)
project(TermGL C CXX)


file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(TermGL ${SOURCES})

target_include_directories(TermGL PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
