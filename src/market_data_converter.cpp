/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include "market_data_converter.h"
#include "converter.h"
#include "yahoo_to_zorro_converter.h"
#include "oanda_to_zorro_converter.h"
#include <memory>

bool MarketDataConverter::convert(Providers dataSource, const std::string &inFilePath, const std::string &outFilePath) {

    std::unique_ptr<Converter> converter;

    switch (dataSource) {
        case Providers::Yahoo:
            converter = std::make_unique<YahooToZorroConverter>();
            break;
        case Providers::Oanda:
            converter = std::make_unique<OandaToZorroConverter>();
            break;
    }

    return converter->convert(inFilePath, outFilePath);
}
