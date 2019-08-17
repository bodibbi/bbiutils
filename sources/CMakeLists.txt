project(bbiutils)

cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
        apputils/src/ModuleManager.cpp
)

set(PUBLIC_HEADER_FILES
        apputils/pub/ModuleManager.h
)

include_directories(
    apputils/pub/
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
add_custom_target(headers SOURCES ${PUBLIC_HEADER_FILES})
