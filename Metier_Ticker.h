#pragma once
#include <array>
#include "Metier_Chart.h"
#include "Metier_TCallback.h"
#include "json.h"
using json = nlohmann::json;

class Ticker
{
    private:
        const std::string SYMBOL = "BTCUSDT";
        const std::string INTERVAL = "1m";
        const std::string APIURL = "https://api.binance.us/api/v3";
        const int MAXHISTORY = 100;

        Chart gChart;
        TickerCallback gCallback;

        std::array<double, 9> FormatBar(json barIn) {
            std::array<double, 9> output;
            for (int x = 0; x < 9; x++)
                if (barIn[x].is_string())
                    output[x] = std::stod(barIn[x].template get<std::string>());
                else
                    output[x] = barIn[x].template get<double>();
            return output;
        }

    public:

        Ticker(Chart &chart) {
            gChart = chart;
        }

        ~Ticker() {}

        //Loads previous 100 candlesticks into 'Bars' vector.
        void Initialize(TickerCallback& callback);

        //Main ticker loop, gets 'SYMBOL' kline/candlestick data from API every
        //  5 seconds and adds data to 'Bars' vector in 'Chart' class every 61 seconds.
        void Run();
};