cmake_minimum_required(VERSION 3.20)
project(cpp-bufferRender VERSION 2.2)
set(CMAKE_CXX_STANDARD 23)

# executable for testing
add_executable(cpp-bufferRender-TEST main.cpp lib/str/bufferRender.cpp lib/str/bufferRender.h lib/str/terminalSize.h lib/str/cursor.h lib/str/terminalSize.cpp lib/str/cursor.cpp lib/str/exBufferRender.cpp lib/str/exBufferRender.h)

add_library(cpp-bufferRender-str lib/str/bufferRender.cpp lib/str/bufferRender.h lib/str/terminalSize.h lib/str/cursor.h lib/str/terminalSize.cpp lib/str/cursor.cpp lib/str/exBufferRender.cpp lib/str/exBufferRender.h)
set_target_properties(cpp-bufferRender-str PROPERTIES PUBLIC_HEADER lib/str/exBufferRender.h)

add_library(cpp-bufferRender-ext lib/ext/DCMP.cpp lib/ext/DCMP.h)