cmake_minimum_required(VERSION 2.8)
project(Pokemon_Thunder_Lightning)

set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
set(PROJECT_BINARY_DIR "./bin")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

include_directories(${PROJECT_BINARY_DIR})
include_directories("./include")
include_directories("./include/tmxlite")
include_directories("./include/tmxlite/detail")

file(GLOB CMAKE_SRCS
    "./src/*.h"
    "./src/*.cpp"
    "./src/tmxlite/*.h"
    "./src/tmxlite/*.cpp"
    "./src/tmxlite/detail/*.h"
    "./src/tmxlite/detail/*.cpp"
    "./src/*.c"
    )

find_package(OpenGL)

set(EXECUTABLE_NAME "Pokemon-Thunder-and-Lightning")
add_executable(${EXECUTABLE_NAME} ${CMAKE_SRCS})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(Thor 2 REQUIRED)
find_package(Threads)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()


include_directories(${SFML_INCLUDE_DIR})
include_directories(${THOR})
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_gl_LIBRARY} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${THOR_LIBRARY})



install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)



