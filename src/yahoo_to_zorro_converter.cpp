/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "yahoo_to_zorro_converter.h"
#include "util.h"

const bool OMIT_TIME = true;

bool YahooToZorroConverter::loadCSVFile(const std::string &path, std::vector<Bar> &bars) {

    std::ifstream ifs(path);
    std::string row;
    Bar lastValidBar;

    if (!ifs.is_open()) {
        std::cerr << "Couldn't open json file" << std::endl;
        return false;
    }

    // Skip first row with labels
    std::getline(ifs, row);

    while (std::getline(ifs, row)) {
        if (!row.empty()) {
            const auto parts = splitString(row, ',');

            if (parts.size() != 7) {
                return false;
            }

            Bar newBar;

            struct std::tm tm{};
            std::istringstream ss(parts[0]);
            ss >> std::get_time(&tm, "%Y-%m-%d");

            char queryTime[80];
            std::strftime(queryTime, 80, "%Y.%m.%d", &tm);
            newBar.m_date = queryTime;

            // If there is a null value then the rest is also null
            if (parts[1] == "null") {
                newBar.m_open = lastValidBar.m_open;
                newBar.m_high = lastValidBar.m_high;
                newBar.m_low = lastValidBar.m_low;
                newBar.m_close = lastValidBar.m_close;
                newBar.m_adjustedClose = lastValidBar.m_adjustedClose;
                newBar.m_volume = lastValidBar.m_volume;
            } else {
                newBar.m_open = std::stod(parts[1]);
                newBar.m_high = std::stod(parts[2]);
                newBar.m_low = std::stod(parts[3]);
                newBar.m_close = std::stod(parts[4]);
                newBar.m_adjustedClose = std::stod(parts[5]);
                newBar.m_volume = std::strtoll(parts[6].c_str(), NULL, 10);
                lastValidBar = newBar;
            }
            bars.push_back(newBar);
        } else {
            return false;
        }
    }

    return true;
}

bool YahooToZorroConverter::saveBarsToCSVFile(const std::string &path, const std::vector<Bar> &bars) {

    std::ofstream file(path);

    if (file.is_open()) {

        for (const auto &bar: bars) {
            file << std::fixed;
            file << std::setprecision(2);
            file << bar.m_date << "," << bar.m_time << "," << bar.m_open << "," << bar.m_high << "," << bar.m_low << ","
                 << bar.m_close
                 << "," << bar.m_volume << std::endl;
        }

        return true;
    }
    return false;
}

bool YahooToZorroConverter::convert(const std::string &inPath, const std::string &outPath) {
    std::vector<Bar> bars;

    if (loadCSVFile(inPath, bars)) {
        return saveBarsToCSVFile(outPath, bars);
    }

    return false;
}
