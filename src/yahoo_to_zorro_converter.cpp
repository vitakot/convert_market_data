/*
Market Data Converter
https://github.com/vitakot/market_data_converter

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "YahooToZorroConverter.h"
#include "nlohmann/json.hpp"

const bool OMIT_TIME = true;

template<typename ValueType>
bool readValue(const nlohmann::json &json, const std::string &key, ValueType &value) {
    nlohmann::json::const_iterator it;

    it = json.find(key);

    if (it != json.end()) {
        value = it.value();
        return true;

    }
    return false;
}

bool YahooToZorroConverter::loadJsonResponse(const std::string &path, std::vector<Bar> &bars) {

    std::ifstream ifs(path);

    if (!ifs.is_open()) {
        std::cerr << "Couldn't open json file" << std::endl;
        return false;
    }

    try {
        nlohmann::json json = nlohmann::json::parse(ifs);
        const auto candles = json["candles"];

        for (const auto &candle : candles) {

            Bar newBar;

            std::string stringValue;
            const auto midPoint = candle["mid"];
            readValue<std::string>(candle, "time", stringValue);

            struct std::tm tm{};
            std::istringstream ss(stringValue);
            ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");

            char queryTime[80];
            std::strftime(queryTime, 80, "%Y.%m.%d", &tm);
            newBar.m_date = queryTime;

            if (!OMIT_TIME) {
                std::strftime(queryTime, 80, "%H:%M:%S", &tm);
                newBar.m_time = queryTime;
            }

            readValue<std::string>(midPoint, "o", stringValue);
            newBar.m_open = std::stod(stringValue);
            readValue<std::string>(midPoint, "h", stringValue);
            newBar.m_high = std::stod(stringValue);
            readValue<std::string>(midPoint, "l", stringValue);
            newBar.m_low = std::stod(stringValue);
            readValue<std::string>(midPoint, "c", stringValue);
            newBar.m_close = std::stod(stringValue);

            bars.push_back(newBar);
        }
        return true;
    }

    catch (nlohmann::json::exception &e) {
        std::cerr << e.what() << std::endl;
        ifs.close();
        return false;
    }
}

bool YahooToZorroConverter::saveBarsToCSVFile(const std::string &path, const std::vector<Bar> &bars) {

    std::ofstream file(path);

    if (file.is_open()) {

        for (const auto &bar : bars) {
            file << std::fixed;
            file << std::setprecision(2);
            file << bar.m_date << "," << bar.m_time << ","<< bar.m_open << "," << bar.m_high << "," << bar.m_low << "," << bar.m_close
                 << "," << bar.m_volume << std::endl;
        }

        return true;
    }
    return false;
}

bool YahooToZorroConverter::convert(const std::string &oandaFilePath, const std::string &csvFilePath) {

    std::vector<Bar> bars;

    if (loadJsonResponse(oandaFilePath, bars)) {
        return saveBarsToCSVFile(csvFilePath, bars);
    }

    return false;
}
