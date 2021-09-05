/*
Convert Market Data
https://github.com/vitakot/convert_market_data

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2021 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef CONVERTER_H
#define CONVERTER_H

struct Converter {

    virtual ~Converter() = default;

    virtual bool convert(const std::string &inPath, const std::string &outPath) = 0;
};

#endif // CONVERTER_H
