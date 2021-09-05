# Convert Market Data
Tool for converting market data from various providers to Zorro .t6 format. Currently Yahoo and Oanda providers asre supported.

## Usage

    convert_market_data [OPTION...]

    -p, --provider arg  Data provider, y - yahoo (default), o - oanda,
                        example: -p y (default: y)  
    -i, --input arg     Path to input csv data file, example: -i
                        "C:\Users\Public\btcusd.csv"
    -o, --output arg    Path to output Zorro data .t6 file, example: -o
                        "C:\Users\Public\btcusd.t6"

    -h, --help          Print usage  

## Dependencies

https://github.com/nlohmann/json  
https://github.com/jarro2783/cxxopts  