cmake_minimum_required(VERSION 3.0)

project(PowerGLFW LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS ${RETRO68_ROOT}/universal/CIncludes/)
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/include)

FILE(GLOB_RECURSE sources src/*.c)

add_library(${PROJECT_NAME} ${sources})

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(${PROJECT_NAME} PUBLIC $ENV{RETRO68_TOOLCHAIN_PATH}/universal/CIncludes/)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/mac_gl)
target_link_libraries(${PROJECT_NAME} WindowsLib InterfaceLib ThreadsLib m gl)

option(BUILD_EXAMPLES "Build the GLFW examples" ON)

if(${BUILD_EXAMPLES})
foreach(prg IN ITEMS boing gears wave windows)
    message(STATUS "Building ${prg}...")
    add_application(
        ${prg} 
        examples/${prg}.c
        # CONSOLE
    )

    set_target_properties(${prg} PROPERTIES COMPILE_FLAGS "-ffunction-sections -mcpu=601 -O3 -Wall -Wextra -Wno-unused-parameter")
    set_target_properties(${prg} PROPERTIES LINK_FLAGS "-Wl,-gc-sections")

    target_link_directories(${prg} PUBLIC lib)
    target_link_libraries(${prg} PowerGLFW)
endforeach()
endif()