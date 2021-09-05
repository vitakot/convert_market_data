/*
Market Data Converter
https://github.com/vitakot/market_data_converter

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include <iostream>
#include "market_data_converter.h"

int main() {
    MarketDataConverter converter;
    auto ret = MarketDataConverter::convert("C:/Trading/seasonality_oanda/30Y-Bond.txt",
                                           "C:/Trading/seasonality_oanda/30Y-Bond.csv");

    if (ret) {
        std::cout << "Converted successfully" << std::endl;
    }
    return 0;
}
