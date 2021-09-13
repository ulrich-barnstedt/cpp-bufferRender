cmake_minimum_required(VERSION 3.20)
project(CBR VERSION 2.2)
set(CMAKE_CXX_STANDARD 23)

add_library(CBR-util lib/util/arrayFunctions.cpp lib/util/arrayFunctions.h lib/util/cursor.h lib/util/cursor.cpp lib/util/terminalSize.h lib/util/terminalSize.cpp)
set_target_properties(CBR-util PROPERTIES PUBLIC_HEADER lib/util/arrayFunctions.h)

add_library(CBR-str lib/str/bufferRender.cpp lib/str/bufferRender.h lib/str/exBufferRender.cpp lib/str/exBufferRender.h)
set_target_properties(CBR-str PROPERTIES PUBLIC_HEADER lib/str/exBufferRender.h)
target_link_libraries(CBR-str CBR-util)
add_executable(CBR-str-TEST test/str/main.cpp)
target_link_libraries(CBR-str-TEST PUBLIC CBR-str)

add_library(CBR-ext lib/ext/DCMP.h lib/ext/Base.h lib/ext/U_DCMP.h)
set_target_properties(CBR-ext PROPERTIES PUBLIC_HEADER lib/ext/DCMP.h)
target_link_libraries(CBR-ext CBR-util)
add_executable(CBR-ext-TEST test/ext/main.cpp)
target_link_libraries(CBR-ext-TEST PUBLIC CBR-ext)