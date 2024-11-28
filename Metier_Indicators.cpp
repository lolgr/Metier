#include <cmath>
#include <array>
#include <string>
#include "Metier_Indicators.h"

double TI::wma(Chart chart, int length, bool includeCurrent) {
    double numT = 0;
    double demT = 0;
    for (int l = 1; l <= length; l++) {
        numT += chart.GetPriceAt(l - (int)includeCurrent) * (length - (l - 1));
        demT += l;
    }
    return numT / demT;
}

// double TI::tr(Chart chart, std::vector<double>& opt_pricesOut, int length, int barsAway) {
//     for (int x = barsAway; x < length; x++) {
//         auto bar = chart.GetBarAt(x).value();
//         auto prevBar = chart.GetBarAt(x + 1).value();
//         double tHigh = bar[2];
//         double tLow = bar[3];
//         double yClose = prevBar[4];
//         double yLow = prevBar[3];

//         double a = tHigh - tLow;
//         double b = std::abs(tHigh - yClose);
//         double c = std::abs(tLow - yClose);
//         double max = std::max(a, std::max(b, c));
//         if (length > 1)
//             opt_pricesOut.push_back(max);
//         else
//             return max;
//     }
//     return -1;
// }

double TI::rma(Chart chart, int length, std::vector<double> opt_prices) {
    /*
        pine_rma(source, length) =>
        alpha = 1 / length
        sum = 0.0
        sum := na(sum[1]) ? 
            ta.sma(source, length) : 
            alpha * source + (1 - alpha) * nz(sum[1])

        pine_rma(x, y) =>
        alpha = y
        sum = 0.0
        sum := (x + (alpha - 1) * nz(sum[1])) / alpha

        true_range() =>
        max(high - low, max(abs(high - close[1]), abs(low - close[1])))
    */
    std::cout << "0" << std::endl;
    int s = opt_prices.empty() ? 1 - opt_prices.size() : 0;
    std::cout << "1" << std::endl;
    // double currentPrice = (s == 0 ? chart.GetPriceAt(0) : opt_prices[s]);
    double currentPrice = chart.GetPriceAt(0);
    double alpha = 1 / length;
    std::cout << "2" << std::endl;
    static std::optional<double> prevSum;
    static std::optional<double> sum;
    if (!prevSum)
        prevSum = 0;
    if (!sum) {
        sum = sma(chart, length);
        for (int x = length - 1; x > 0; x--) {
            currentPrice = chart.GetPriceAt(x);
            sum = (alpha * currentPrice + (1 - alpha) * sum.value());
        }
    } else
        sum = (alpha * currentPrice + (1 - alpha) * sum.value());
    // else
    //     sum = (currentPrice + (alpha - 1) * prevSum.value()) / alpha;
    // prevSum = sum ? sum : 0;
    // std::cout << sum.value() << std::endl;
    return sum.value();
}

double TI::sma(Chart chart, int length, std::vector<double> opt_prices, bool includeCurrent) {
    double total = 0;
    int size = opt_prices.size();
    for (int x = 0; x < length; x++)
        if (size >= length)
            total += opt_prices[x];
        else
            total += chart.GetPriceAt(x);
    return total / (double)length;
}

double TI::mfi(Chart chart, int length, std::vector<double> opt_prices, std::vector<double> opt_volume) {
    double upper;
    double lower;
    for (int x = 0; x < length; x++) {
        double volume = chart.GetBarAt(x).volume;
        double price = opt_prices.empty() ? chart.GetPriceAt(x) : opt_prices[x];
        double prevPrice = opt_prices.empty() ? chart.GetPriceAt(x + 1) : opt_prices[x + 1];
        double change = price - prevPrice;
        upper += volume * (change <= 0.0 ? 0.0 : price);
        lower += volume * (change >= 0.0 ? 0.0 : price);
    }
    return 100.0 - (100.0 / (1.0 + upper / lower));
}

std::vector<double> TI::hlc3(Chart chart, int length) {
    std::vector<double> output; 
    for (int x = 0; x < length + 1; x++) {
        Bar bar = chart.GetBarAt(x);
        double high = bar.high;
        double low = bar.low;
        double close = bar.close;
        output.push_back((high + low + close) / 3);
    }
    return output;
}