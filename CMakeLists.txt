cmake_minimum_required(VERSION 3.20)
project(cpp-bufferRender)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp-bufferRender-TEST main.cpp lib/bufferRender.cpp lib/bufferRender.h lib/terminalSize.h lib/cursor.h lib/terminalSize.cpp lib/cursor.cpp lib/exBufferRender.cpp lib/exBufferRender.h)

add_library(cpp-bufferRender lib/bufferRender.cpp lib/bufferRender.h lib/terminalSize.h lib/cursor.h lib/terminalSize.cpp lib/cursor.cpp lib/exBufferRender.cpp lib/exBufferRender.h)
set_target_properties(cpp-bufferRender PROPERTIES PUBLIC_HEADER lib/exBufferRender.h)