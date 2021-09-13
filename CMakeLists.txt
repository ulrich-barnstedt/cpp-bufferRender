cmake_minimum_required(VERSION 3.20)
project(cpp-bufferRender VERSION 2.2)
set(CMAKE_CXX_STANDARD 23)

add_library(cpp-bufferRender-str lib/str/bufferRender.cpp lib/str/bufferRender.h lib/str/terminalSize.h lib/str/terminalSize.cpp lib/str/exBufferRender.cpp lib/str/exBufferRender.h)
set_target_properties(cpp-bufferRender-str PROPERTIES PUBLIC_HEADER lib/str/exBufferRender.h)
add_executable(cbr-str-TEST test/str/main.cpp)
target_link_libraries(cbr-str-TEST PUBLIC cpp-bufferRender-str)

add_library(cpp-bufferRender-ext lib/ext/DCMP.h lib/ext/cursor.h lib/ext/cursor.cpp lib/ext/Base.h)
set_target_properties(cpp-bufferRender-ext PROPERTIES PUBLIC_HEADER lib/ext/DCMP.h)
add_executable(cbr-ext-TEST test/ext/main.cpp)
target_link_libraries(cbr-ext-TEST PUBLIC cpp-bufferRender-ext)