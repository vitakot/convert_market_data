/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef MARKET_DATA_CONVERTER_TYPES_H
#define MARKET_DATA_CONVERTER_TYPES_H

#include <ctime>

static const std::time_t HISTORY_LENGTH_IN_S = 31556926; // Number of seconds in 1 year

enum class Providers : char {
    Yahoo = 'y',
    Oanda = 'o'
};

struct Bar {
    std::string m_date;
    std::string m_time = "00:00:00";
    double m_open = 0.0;
    double m_high = 0.0;
    double m_low = 0.0;
    double m_close = 0.0;
    double m_adjustedClose = 0.0;
    std::int64_t m_volume = 0.0;
};

#endif //MARKET_DATA_CONVERTER_TYPES_H
