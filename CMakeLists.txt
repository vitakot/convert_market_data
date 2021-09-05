cmake_minimum_required(VERSION 3.20)
project(ConvertMarketData)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(json)
add_subdirectory(cxxopts)

include_directories(src)
include_directories(json/include)

add_executable(convert_market_data
        main.cpp
        src/market_data_converter.cpp
        src/market_data_converter.h
        src/yahoo_to_zorro_converter.cpp
        src/yahoo_to_zorro_converter.h
        src/oanda_to_zorro_converter.cpp
        src/oanda_to_zorro_converter.h
        src/util.h
        src/types.h)

target_link_libraries(convert_market_data cxxopts)
