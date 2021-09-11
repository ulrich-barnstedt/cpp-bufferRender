cmake_minimum_required(VERSION 3.20)
project(cpp-bufferRender)

set(CMAKE_CXX_STANDARD 23)

add_executable(strlib main.cpp lib/bufferRender.cpp lib/bufferRender.h lib/terminalSize.h lib/cursor.h lib/terminalSize.cpp lib/cursor.cpp lib/exBufferRender.cpp lib/exBufferRender.h)
