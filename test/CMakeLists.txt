cmake_minimum_required(VERSION 3.20)
project(CBR-TESTING)
set(CMAKE_CXX_STANDARD 23)

add_executable(CBR-str-TEST str/main.cpp)
target_link_libraries(CBR-str-TEST PUBLIC CBR-str)

add_executable(CBR-ext-TEST ext/main.cpp)
target_link_libraries(CBR-ext-TEST PUBLIC CBR-ext)