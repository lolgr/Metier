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
        double tr(Chart chart, std::vector<double>& opt_pricesOut,  int length = 1, int barsAway = 0);
        
        //Average True Rage
        double atr(Chart chart, std::vector<double>& opt_pricesOut,  int length = 1, int barsAway = 0);

        //Relative Moving Average
        static double rma(Chart chart, int length, std::vector<double> opt_prices = std::vector<double>());

        //Simple Moving Average
        // ---Need to improve efficiency by using static variables and avoid looping each time.
        static double sma(Chart chart, int length, std::vector<double> opt_prices = std::vector<double>(), bool includeCurrent = true);

        //Money Flow Index
        static double mfi(Chart chart, int length, std::vector<double> opt_prices = std::vector<double>(), std::vector<double> opt_volume = std::vector<double>());

        //High Low Close over 3
        static std::vector<double> hlc3(Chart chart, int length);
};

#endif