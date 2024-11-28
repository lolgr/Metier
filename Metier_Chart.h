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
        std::function<T(Series<T>*, int, int)> seriesMethod;
        Series<T>* series;
        int start, end;
        Chart* chart;
        T data;

    public:
        Series(T d, std::function<T(Chart*, int, int)> m, Chart* c, int s, int e) :
        data(d), method(m), chart(c), start(s), end(e) { }

        Series(T d, std::function<T(Series<T>*, int, int)> m, Series<T>* c, int s, int e) :
        data(d), seriesMethod(m), series(c), start(s), end(e) { }

        operator T() const {
            return data;
        }

        T operator[](unsigned int i) {
            return method ? method(chart, start + i, end + i) : seriesMethod(series, start + i, end + i);
        }

};

struct Bar {
    double low;
    double high;
    double close;
    double volume;

    Bar(std::array<double, 9> d) : 
        high(d[2]), low(d[3]), close(d[4]), volume(d[5]) {}
};

class Chart {
    private:
        std::array<std::array<double, 9>, 2> DayBars;
        std::vector<Bar> Bars;

    public:
        Bar GetBarAt(int at);

        bool SetBarAt(int at, Bar bar);

        double GetLowestInSeries(Series<double> input, int length);

        double GetHighestInSeries(Series<double> input, int length);
        
        static Series<double> High(Chart* chart, int start = 0, int end = 0);

        static Series<double> Low(Chart* chart, int start = 0, int end = 0);

        static Series<double> Close(Chart* chart, int start = 0, int end = 0);

        Series<double> toSeries() {
            return Series<double>(Close(this, 0), Close, this, 0, 0);
        }

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

        //--Obsolete function--
        double GetLowAt(int barsAway) {
            return GetBarAt(barsAway).low;
        }

        //--Obsolete function--
        double GetHighAt(int barsAway) {
            return GetBarAt(barsAway).high;
        }

        double GetDayHighAt(int daysAgo) {
            return GetDayBarAt(daysAgo)[2];
        }

        double GetDayLowAt(int daysAgo) {
            return GetDayBarAt(daysAgo)[3];
        }

        void AddBar(Bar bar) {
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
