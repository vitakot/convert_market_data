/*
Market Data Converter
https://github.com/vitakot/market_data_converter

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef MARKET_DATA_CONVERTER_H
#define MARKET_DATA_CONVERTER_H

#include <string>
#include <vector>
#include "types.h"

struct Bar {
    std::string m_date;
    std::string m_time = "00:00:00";
    double m_open = 0.0;
    double m_high = 0.0;
    double m_low = 0.0;
    double m_close = 0.0;
    std::int64_t m_volume = 0.0;
};

class MarketDataConverter {

public:

    static bool convert(Providers dataSource, const std::string &inFilePath, const std::string &outFilePath);
};


#endif // MARKET_DATA_CONVERTER_H
