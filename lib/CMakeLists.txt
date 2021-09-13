cmake_minimum_required(VERSION 3.20)
project(CBR-LIBRARY)
set(CMAKE_CXX_STANDARD 23)

add_library(CBR-util util/cursor.h util/cursor.cpp util/terminalSize.h util/terminalSize.cpp)

add_library(CBR-str str/bufferRender.cpp str/bufferRender.h str/exBufferRender.cpp str/exBufferRender.h)
set_target_properties(CBR-str PROPERTIES PUBLIC_HEADER str/exBufferRender.h)
target_link_libraries(CBR-str CBR-util)

add_library(CBR-ext ext/DCMP.h ext/Base.h ext/U_DCMP.h)
set_target_properties(CBR-ext PROPERTIES PUBLIC_HEADER ext/DCMP.h)
target_link_libraries(CBR-ext CBR-util)