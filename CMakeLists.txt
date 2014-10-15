cmake_minimum_required(VERSION 2.8.4)
project(sdl)

include(FindPkgConfig)
pkg_search_module(SDL REQUIRED sdl)
find_package(Threads)
include_directories(${SDL_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c*)

add_executable(sdl ${SRC_FILES})
target_link_libraries(sdl ${CMAKE_THREAD_LIBS_INIT} ${SDL_LIBRARIES})
