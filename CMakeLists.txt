cmake_minimum_required(VERSION 3.0)

project(PowerGLFW LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS ${RETRO68_ROOT}/universal/CIncludes/)
include_directories(${RETRO68_ROOT}/universal/CIncludes/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/mac_gl)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
link_libraries(gl)

FILE(GLOB_RECURSE sources src/*.c)

add_library(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} WindowsLib InterfaceLib ThreadsLib m)

if(PLATFORM MATCHES retroppc)
    foreach(prg IN ITEMS boing gears splitview wave windows)
        message(STATUS "Building ${prg}...")
        add_application(
            ${prg} 
            examples/${prg}.c
        )

        set_target_properties(${prg} PROPERTIES COMPILE_FLAGS "-ffunction-sections -mcpu=601 -O3 -Wall -Wextra -Wno-unused-parameter")
        set_target_properties(${prg} PROPERTIES LINK_FLAGS "-Wl,-gc-sections")

        target_link_directories(${prg} PUBLIC lib)
        target_link_libraries(${prg} PowerGLFW)
    endforeach()
endif()