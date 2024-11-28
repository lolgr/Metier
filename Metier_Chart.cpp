#include "Metier_Chart.h"
#include <optional>

Bar Chart::GetBarAt(int at) {
    int s = Bars.size();
    int i = s - 1 - at;
    if (i < 0)
        return GetBarAt(s);
    return Bars[i];
}

bool Chart::SetBarAt(int at, Bar bar) {
    int s = Bars.size();
    int i = s - 1 - at;
    if (i < 0)
        return false;
    Bars[i] = bar;
    return true;
}

Series<double> Chart::High(Chart* chart, int start, int end) {
    return Series<double>(chart->GetBarAt(start).high, High, chart, start, end);
}

Series<double> Chart::Low(Chart* chart, int start, int end) {
    return Series<double>(chart->GetBarAt(start).low, Low, chart, start, end);
}

Series<double> Chart::Close(Chart* chart, int start, int end) {
    return Series<double>(chart->GetBarAt(start).close, Close, chart, start, end);
}

double Chart::GetLowestInSeries(Series<double> input, int length) {
    double lowest = input[0];
    for (int x = 1; x < length; x++)
        if (input[x] < lowest)
            lowest = input[x];
    return lowest;
}

double Chart::GetHighestInSeries(Series<double> input, int length) {
    double highest = input[0];
    for (int x = 1; x < length; x++)
        if (input[x] > highest)
            highest = input[x];
    return highest;
}

//--Obsolete function--
std::vector<double> Chart::GetPricesInRange(int barsAway) {
    std::vector<double> output;
    for (int x = 0; x < barsAway; x++)
        output.push_back(GetPriceAt(x));
    return output;
}

//--Obsolete function--
std::vector<double> Chart::GetHighsInRange(int barsAway) {
    std::vector<double> output;
    for (int x = 0; x < barsAway; x++)
        output.push_back(GetHighAt(x));
    return output;
}

//--Obsolete function--
std::vector<double> Chart::GetLowsInRange(int barsAway) {
    std::vector<double> output;
    for (int x = 0; x < barsAway; x++)
        output.push_back(GetLowAt(x));
    return output;
}

//--Obsolete function--
double Chart::GetPriceAt(int barsAway, int barCount) {
    // return barCount == -1 ? GetBarAt(barsAway).value()[4] : GetBarAt(barsAway, barCount).value()[4];
    return barCount == -1 ? GetBarAt(barsAway).close : 0;
}

//--Obsolete function--
double Chart::GetLowest(std::vector<double> pricesIn) {
    double lowest = pricesIn[0];
    for (int x = 0; x < pricesIn.size(); x++)
        if (pricesIn[x] < lowest)
            lowest = pricesIn[x];
    return lowest;
}

//--Obsolete function--
double Chart::GetHighest(std::vector<double> pricesIn) {
    double highest = pricesIn[0];
    for (int x = 0; x < pricesIn.size(); x++)
        if (pricesIn[x] > highest)
            highest = pricesIn[x];
    return highest;
}