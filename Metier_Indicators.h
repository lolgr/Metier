#pragma once
#include <vector>
#include <array>
#include <string>
#include <iostream>
#include "Metier_Chart.h"

#ifndef TI_H
#define TI_H

//Technical Indicators
class TI {
    public:
        //Weighted Moving Average
        // ---Need to improve efficiency by using static variables and avoid looping each time.
        
        static double wma(Chart chart, int length, bool includeCurrent = true);

        //Each function would need a range for the chart
        //Each function would return a Series<T> of a new object that has the function passed into it.
        /*Series, (data[0], 
            funtion, 
            chart, 
            start, //number of bars back or length so 100 to start 100 bars back
            end) () //numbers of bars back so 0 for until recent
            
        */

        // double TI::wma(Chart chart, int length, bool includeCurrent) {
        //     double numT = 0;
        //     double demT = 0;
        //     for (int l = 1; l <= length; l++) {
        //         numT += chart.GetPriceAt(l - (int)includeCurrent) * (length - (l - 1));
        //         demT += l;
        //     }
        //     return numT / demT;
        // }

        // Series<double> wma(Series<double> values, int start, int end) {
        //     double numT = 0;
        //     double demT = 0;

        //     int length = end - start + 1
        //     for (int x = 0; x < length; x++) {
        //         numT += values[x * (length - x)];
        //         demT += x + 1;
        //     }

        //     return Series<double>(numT / demT, wma, chart, start, end);
        // }

        //True Range
        // double tr(Chart chart, std::vector<double>& opt_pricesOut,  int length = 1, int barsAway = 0);


//  It is math.max(high - low, math.abs(high - close[1]), math.abs(low - close[1])).
        static Series<double> tr(Chart* chart, int start = 0, int end = 0) {
            double max;
            auto high = Chart::High(chart);
            auto low = Chart::Low(chart);
            auto close = Chart::Close(chart);

            max = std::max({high[start] - low[start], std::abs(high[start] - close[start + 1]), std::abs(low[start] - close[start + 1])});
            
            // std::cout << high - low << " --- " << std::abs(high[start] - close[start + 1]) << " --- " << std::abs(low[start] - close[start + 1]) << " -- Max = " << max << std::endl;
            
            return Series<double>(max, tr, chart, start, end);
        }

        //Average True Rage
        double atr(Chart chart, std::vector<double>& opt_pricesOut,  int length = 1, int barsAway = 0);

        //Relative Moving Average
        static double rma(Chart chart, int length, std::vector<double> opt_prices = std::vector<double>());

        //Simple Moving Average
        // ---Need to improve efficiency by using static variables and avoid looping each time.
        static double sma(Chart chart, int length, std::vector<double> opt_prices = std::vector<double>(), bool includeCurrent = true);
        
        /*
            double total = 0;
            int size = opt_prices.size();
            for (int x = 0; x < length; x++)
                if (size >= length)
                    total += opt_prices[x];
                else
                    total += chart.GetPriceAt(x);
            return total / (double)length;
        */

        static Series<double> smaN(Series<double>* input, int start = 1, int end = 0) {
            double total = 0;
            for (int x = end; x < start; x++)
                total += (*input)[x];
            double out = total / (start - end);
            return Series<double>(out, smaN, input, start, end);
        }

        //Money Flow Index
        static double mfi(Chart chart, int length, std::vector<double> opt_prices = std::vector<double>(), std::vector<double> opt_volume = std::vector<double>());

        //High Low Close over 3
        static std::vector<double> hlc3(Chart chart, int length);
};

#endif