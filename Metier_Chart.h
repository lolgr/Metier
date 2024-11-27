#pragma once
#include <vector>
#include <string>
#include <array>
#include <optional>
#include <functional>
#include "Metier_Series.h"

#ifndef Chart_H
#define Chart_H

class Chart;

template <typename T> class Series {
    private:
        std::function<T(Chart*, int, int)> method;
        int start, end;
        Chart* chart;
        T data;

    public:

        Series(T d, std::function<T(Chart*, int, int)> m, Chart* c, int s, int e) :
        data(d), method(m), chart(c), start(s), end(e) { }

        operator T() const {
            return data;
        }

        T operator[](unsigned int i) {
            return method(chart, start + i, end + i);
        }

};

class Chart
{
    private:
        std::vector<std::array<double, 9>> Bars;
        std::array<std::array<double, 9>, 2> DayBars;

    public:
        //barsAway starts at 0, meaning Bars[0] is the newest bar while Bars[Bars.size() - 1] is the oldest.
        bool SetBarAt(int barsAway, std::array<double, 9> bar, int barCount = -1);

        std::optional<std::array<double, 9>> GetBarAt(int barsAway, int barCount = -1);

        double GetLowestInSeries(Series<double> input, int length);

        double GetHighestInSeries(Series<double> input, int length);
        
        static Series<double> High(Chart* chart, int start, int end = 0);

        static Series<double> Low(Chart* chart, int start, int end = 0);

        static Series<double> Close(Chart* chart, int start, int end = 0);

        //--Obsolete function--
        double GetPriceAt(int barsAway, int barCount = -1);
        
        //--Obsolete function--
        double GetLowest(std::vector<double> pricesIn);

        //--Obsolete function--
        double GetHighest(std::vector<double> pricesIn);
        
        //--Obsolete function--
        double GetHighestInRange(int length);

        //--Obsolete function--
        double GetLowestInRange(int length);

        //--Obsolete function--
        std::vector<double> GetPricesInRange(int barsAway);

        //--Obsolete function--
        std::vector<double> GetHighsInRange(int barsAway);
        
        //--Obsolete function--
        std::vector<double> GetLowsInRange(int barsAway);

        Series<double> toSeries() {
            return Series<double>(GetPrice(this, 0), GetPrice, this, 0, 0);
        }

        //--Obsolete function--
        double GetLowAt(int barsAway) {
            return GetBarAt(barsAway).value()[3];
        }

        //--Obsolete function--
        double GetHighAt(int barsAway) {
            return GetBarAt(barsAway).value()[2];
        }

        double GetDayHighAt(int daysAgo) {
            return GetDayBarAt(daysAgo)[2];
        }

        double GetDayLowAt(int daysAgo) {
            return GetDayBarAt(daysAgo)[3];
        }

        void AddBar(std::array<double, 9> bar) {
            Bars.push_back(bar);
        }

        std::array<double, 9> GetDayBarAt(int daysAgo) {
            return DayBars[1 - daysAgo];
        }

        void SetDayBarAt(int daysAgo, std::array<double, 9> bar) {
            DayBars[1 - daysAgo] = bar;
        }

        int GetBarCount() {
            return static_cast<int>(Bars.size());
        }

};

#endif
