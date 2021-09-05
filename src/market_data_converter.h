/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef MARKET_DATA_CONVERTER_H
#define MARKET_DATA_CONVERTER_H

#include <string>
#include <vector>
#include "types.h"

class MarketDataConverter {

public:

    static bool convert(Providers dataSource, const std::string &inFilePath, const std::string &outFilePath);
};

#endif // MARKET_DATA_CONVERTER_H
