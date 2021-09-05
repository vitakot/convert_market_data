/*
Market Data Converter
https://github.com/vitakot/market_data_converter

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef YAHOO_TO_ZORRO_CONVERTER_H
#define YAHOO_TO_ZORRO_CONVERTER_H

#include <string>
#include <vector>

struct Bar {
    std::string m_date;
    std::string m_time = "00:00:00";
    double m_open = 0.0;
    double m_high = 0.0;
    double m_low = 0.0;
    double m_close = 0.0;
    std::int64_t m_volume = 0.0;
};

class YahooToZorroConverter {

    static bool loadJsonResponse(const std::string &path, std::vector<Bar> &bars);

    static bool saveBarsToCSVFile(const std::string &path, const std::vector<Bar> &bars);

public:

    static bool convert(const std::string &oandaFilePath, const std::string &csvFilePath);
};


#endif // YAHOO_TO_ZORRO_CONVERTER_H
