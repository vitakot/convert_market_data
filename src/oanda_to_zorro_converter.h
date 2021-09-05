/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef OANDA_TO_ZORRO_CONVERTER_H
#define OANDA_TO_ZORRO_CONVERTER_H

#include "converter.h"
#include "types.h"
#include <string>
#include <vector>

class OandaToZorroConverter : public Converter {

    static bool loadJsonResponse(const std::string &path, std::vector<Bar> &bars);

    static bool saveBarsToCSVFile(const std::string &path, const std::vector<Bar> &bars);

public:

    bool convert(const std::string &inPath, const std::string &outPath) override;
};


#endif // OANDA_TO_ZORRO_CONVERTER_H
