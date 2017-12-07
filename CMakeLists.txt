cmake_minimum_required(VERSION 2.8)
project(Pokemon_Thunder_Lightning)

set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
set(PROJECT_BINARY_DIR "./bin")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++14")

configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

include_directories(${PROJECT_BINARY_DIR})
include_directories("./include")
include_directories("./include/STP")
include_directories("./include/STP/Core")
include_directories("./include/tmx")
include_directories("./include/pugixml")

file(GLOB CMAKE_SRCS
    "./src/*.h"
    "./src/*.cpp"
    "./src/*/*.h"
    "./src/*/*.hpp"
    "./src/*/*.cpp"
    "./src/*.c"
    )

find_package(OpenGL)

set(EXECUTABLE_NAME "Pokemon-Thunder-and-Lightning")
add_executable(${EXECUTABLE_NAME} ${CMAKE_SRCS})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(Thor 2 REQUIRED)
find_package(Box2D REQUIRED)
find_package(PUGIXML REQUIRED)
find_package(Threads)

find_package( ZLIB REQUIRED )
if ( NOT ZLIB_FOUND )
    message(FATAL_ERROR "Could not find zlib")
endif()

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()
if(NOT PUGIXML_FOUND)
    message(FATAL_ERROR "Could not find pugixml")
endif()
if(NOT BOX2D_FOUND)
    message(FATAL_ERROR "Could not find pugixml")
endif()


include_directories(${SFML_INCLUDE_DIR})
include_directories(${PUGIXML_INCLUDE_DIR})
include_directories( ${ZLIB_INCLUDE_DIRS} )
include_directories(${BOX2D_INCLUDE_DIR})
include_directories(${THOR})
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_gl_LIBRARY} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${THOR_LIBRARY} ${PUGIXML_LIBRARY} ${ZLIB_LIBRARIES} ${BOX2D_LIBRARY})



install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)



