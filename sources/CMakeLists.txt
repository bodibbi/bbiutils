project(bbiutils)

cmake_minimum_required(VERSION 2.8)

set(SOURCE_FILES
    apputils/src/GenericLogger.cpp
    apputils/src/ModuleManager.cpp
    apputils/src/SimpleLogger.cpp
)

set(PUBLIC_HEADER_FILES
    apputils/pub/GenericLogger.h
    apputils/pub/ModuleManager.h
    apputils/pub/SimpleLogger.h
)

include_directories(
    apputils/pub/
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
add_custom_target(headers SOURCES ${PUBLIC_HEADER_FILES})
