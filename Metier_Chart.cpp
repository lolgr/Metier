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

std::vector<double> Chart::GetPricesInRange(int barsAway) {
    std::vector<double> output;
    for (int x = 0; x < barsAway; x++)
        output.push_back(GetPriceAt(x));
    return output;
}

std::vector<double> Chart::GetHighsInRange(int barsAway) {
    std::vector<double> output;
    for (int x = 0; x < barsAway; x++)
        output.push_back(GetHighAt(x));
    return output;
}

std::vector<double> Chart::GetLowsInRange(int barsAway) {
    std::vector<double> output;
    for (int x = 0; x < barsAway; x++)
        output.push_back(GetLowAt(x));
    return output;
}

double Chart::GetPriceAt(int barsAway, int barCount) {
    return barCount == -1 ? GetBarAt(barsAway).value()[4] : GetBarAt(barsAway, barCount).value()[4];
}

double Chart::GetLowest(std::vector<double> pricesIn) {
    double lowest = pricesIn[0];
    for (int x = 0; x < pricesIn.size(); x++)
        if (pricesIn[x] < lowest)
            lowest = pricesIn[x];
    return lowest;
}

double Chart::GetHighest(std::vector<double> pricesIn) {
    double highest = pricesIn[0];
    for (int x = 0; x < pricesIn.size(); x++)
        if (pricesIn[x] > highest)
            highest = pricesIn[x];
    return highest;
}

// double Chart::GetHighestInRange(int length) {
//     double highest = GetPriceAt(0);
//     for (int x = 0; x < length; x++) {
//         double price = GetPriceAt(x);
//         if (price > highest)
//             highest = price;
//     }
//     return highest;
// }

// double Chart::GetLowestInRange(int length) {
//     double lowest = GetPriceAt(0);
//     for (int x = 0; x < length; x++) {
//         double price = GetPriceAt(x);
//         if (price < lowest)
//             lowest = price;
//     }
//     return lowest;
// }
