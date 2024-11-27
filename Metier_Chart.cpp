#include "Metier_Chart.h"
#include <optional>

bool Chart::SetBarAt(int barsAway, std::array<double, 9> bar, int barCount) {
    int s = barCount != -1 ? barCount : static_cast<int>(Bars.size());
    int i = s - 1 - barsAway;
    if (i < 0)
        return false;
    Bars[i] = bar;
    return true;
}

std::optional<std::array<double, 9>> Chart::GetBarAt(int barsAway, int barCount) {
    int s = barCount != -1 ? barCount : static_cast<int>(Bars.size());
    int i = s - 1 - barsAway;
    if (i < 0)
        return std::nullopt;
    return Bars[i];
}

Series<double> Chart::High(Chart* chart, int start, int end) {
    return Series<double>(static_cast<double>(chart->GetBarAt(start).value()[2]), GetHigh, chart, start, end);
}

Series<double> Chart::Low(Chart* chart, int start, int end) {
    return Series<double>(static_cast<double>(chart->GetBarAt(start).value()[3]), GetLow, chart, start, end);
}

Series<double> Chart::Close(Chart* chart, int start, int end) {
    return Series<double>(static_cast<double>(chart->GetBarAt(start).value()[4]), GetPrice, chart, start, end);
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
    return barCount == -1 ? GetBarAt(barsAway).value()[4] : GetBarAt(barsAway, barCount).value()[4];
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