cmake_minimum_required(VERSION 3.20)
project(DataConverter)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(cxxopts)
include_directories(src)

add_executable(market_data_converter
        main.cpp
        src/market_data_converter.cpp
        src/yahoo_to_zorro_converter.cpp
        src/oanda_to_zorro_converter.cpp
        src/util.h
        src/types.h)

target_link_libraries(market_data_converter cxxopts)
