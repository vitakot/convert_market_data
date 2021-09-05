/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include <iostream>
#include <cxxopts.hpp>
#include "market_data_converter.h"

int main(int argc, char **argv) {

    std::string pr(" ");
    Providers provider;
    std::string inputFilePath;
    std::string outputFilePath;
    cxxopts::Options options("convert_market_data",
                             "Utility for converting market data from various data vendors, currently supports Oanda and Yahoo");
    cxxopts::ParseResult parseResult;

    pr[0] = static_cast<char>(Providers::Yahoo);

    options.add_options()
            ("p,provider", "Data provider, y - Yahoo (default), o - Oanda, example: -p y",
             cxxopts::value<char>()->default_value(pr))
            ("i,input", R"(Path to input csv data file, example: -i "C:\Users\Public\btcusd.csv" )",
             cxxopts::value<std::string>())
            ("o,output", R"(Path to output Zorro data .t6 file, example: -o "C:\Users\Public\btcusd.t6" )",
             cxxopts::value<std::string>())
            ("h,help", "Print usage");
    try {
        parseResult = options.parse(argc, argv);
    }
    catch (cxxopts::OptionException &ex) {
        std::cout << "Wrong parameters!" << std::endl << std::endl;
        std::cout << options.help() << std::endl;
        exit(0);
    }

    provider = (Providers) parseResult["provider"].as<char>();

    if (parseResult.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    if (static_cast<Providers>(provider) != Providers::Yahoo &&
        static_cast<Providers>(provider) != Providers::Oanda) {
        std::cout << "Wrong provider!" << std::endl << std::endl;
        std::cout << options.help() << std::endl;
        exit(0);
    }

    if (parseResult.count("input")) {
        inputFilePath = parseResult["input"].as<std::string>();
    } else {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    if (parseResult.count("output")) {
        outputFilePath = parseResult["output"].as<std::string>();
    } else {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    bool ret = MarketDataConverter::convert(provider, inputFilePath, outputFilePath);

    if (ret) {
        std::cout << "Converted successfully" << std::endl;
    }

    return 0;
}
