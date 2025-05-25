cmake_minimum_required(VERSION 3.28)
project(Arkanoid)

set(STB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/stb-master)

include(ExternalProject)
ExternalProject_Add(
    stb
    PREFIX ${STB_DIR}
    GIT_REPOSITORY https://github.com/nothings/stb.git
    GIT_TAG master
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

include_directories(${STB_DIR})

file(GLOB SOURCES src/*.cpp)
add_executable(Arkanoid ${SOURCES})

target_include_directories(Arkanoid PRIVATE include)
target_include_directories(Arkanoid PRIVATE ${STB_DIR}/src/stb)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(Arkanoid PRIVATE glfw)
target_link_libraries(Arkanoid PRIVATE OpenGL::GL)
