cmake_minimum_required(VERSION 2.6)
project("LargerDimension31")
SET(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

if(${MINGW})
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++1y")
    SET(platform "mingw")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
        SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DWINFOIREU")
    endif()
endif(${MINGW})

if(${UNIX})
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14")
    SET(platform "gcc")
endif(${UNIX})

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")


find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found")
endif(NOT SFML_FOUND)

include_directories(${SFML_INCLUDE_DIR})

file(
    GLOB_RECURSE
    files
    src/*.cpp
    include/*.hpp
)


find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE} doxygen.conf)
endif(DOXYGEN_FOUND)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${files})
else(WIN32)
    add_executable(${PROJECT_NAME} ${files})
endif(WIN32)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
