cmake_minimum_required(VERSION 2.8)
project(Pokemon_Thunder_Lightning)

set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
set(PROJECT_BINARY_DIR "./bin")
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

include_directories(${PROJECT_BINARY_DIR})
include_directories("./include")

file(GLOB CMAKE_SRCS
    "./src/*.h"
    "./src/*.cpp"
    )


set(EXECUTABLE_NAME "Pokemon-Thunder-and-Lightning")
add_executable(${EXECUTABLE_NAME} ${CMAKE_SRCS})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)

