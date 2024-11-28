#pragma once
#include <array>
#include "Metier_Chart.h"
#include "Metier_TCallback.h"
#include "Metier_CurlWrapper.h"
#include "json.h"
using json = nlohmann::json;

#ifndef TICKER_H
#define TICKER_H

class Ticker
{
    private:
        inline static std::string SYMBOL = "BTCUSDT";
        inline static std::string INTERVAL = "1m";
        inline static std::string APIURL = "https://api.binance.us/api/v3";
        static const int MAXHISTORY = 100;

        Chart gChart;
        TickerCallback gCallback;

        bool CompareBars(Bar a, Bar b);

        json RequestJson(std::string limit = "1", std::string interval = INTERVAL) {
            CurlRequest client;
            return json::parse(client.Get(APIURL + "/klines?limit=" + limit + "&interval=" + interval + "&symbol=" + SYMBOL));
        }

        json RequestJson(int limit, std::string interval = INTERVAL) {
            CurlRequest client;
            return RequestJson(std::to_string(limit), interval);
        }

        std::array<double, 9> FormatBar(json barIn) {
            std::array<double, 9> output;
            for (int x = 0; x < 9; x++)
                if (barIn[x].is_string())
                    output[x] = std::stod(barIn[x].template get<std::string>());
                else
                    output[x] = barIn[x].template get<double>();
            return output;
        }

        Bar FormatJson(json barIn) {
            std::array<double, 9> output;
            for (int x = 0; x < 9; x++)
                if (barIn[x].is_string())
                    output[x] = std::stod(barIn[x].template get<std::string>());
                else
                    output[x] = barIn[x].template get<double>();
            return Bar(output);
        }

    public:

        Ticker(Chart &chart) {
            gChart = chart;

            // SYMBOL = "BTCUSDT";
            // INTERVAL = "1m";
            // APIURL = "https://api.binance.us/api/v3";
        }

        ~Ticker() {}

        //Loads previous 100 candlesticks into 'Bars' vector.
        void Initialize(TickerCallback& callback);

        //Main ticker loop, gets 'SYMBOL' kline/candlestick data from API every
        //  5 seconds and adds data to 'Bars' vector in 'Chart' class every 61 seconds.
        void Run();
};

// std::string Ticker::SYMBOL = "BTCUSDT";
// std::string Ticker::INTERVAL = "1m";
// std::string Ticker::APIURL = "https://api.binance.us/api/v3";

#endif