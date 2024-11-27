#include "Metier_TCallback.h"
#include "Metier_Indicators.h"
#include <unistd.h>
#include <math.h>

static int prevTrend;
static int trend;
static double prevUp;
static double up;
static double prevDown;
static double down;

void TickerCallback::OnClose(Chart &chart) {
    if (buySignal && shares == 0.0) {
        shares = balance / chart.GetPriceAt(0);
        balance -= chart.GetPriceAt(0) * shares;
        std::cout << "\t\tBought At: " << chart.GetPriceAt(0) << " Bal: " << balance << std::endl;
    }
    else if (sellSignal && shares > 0.0) {
        balance += chart.GetPriceAt(0) * shares;
        shares = 0.0;
        std::cout << "\t\tSold At: " << chart.GetPriceAt(0) << " Bal: " << balance << std::endl;
    }

    prevTrend = trend;
    prevUp = up;
    prevDown = down;
}

void TickerCallback::OnOpen(Chart &chart) {
    int nextTrend = 0;
    double maxLowPrice = chart.GetLowAt(1);
    double minHighPrice = chart.GetHighAt(1);

    double atrHigh = 0.0;
    double atrLow = 0.0;
    double arrowUp = 0.0;
    double arrowDown = 0.0;

    double atr2 = 0;
    double dev = 2 * atr2;

    double highPrice = chart.GetHighest(chart.GetHighsInRange(2));
    double lowPrice = chart.GetLowest(chart.GetLowsInRange(2));

    // for(double x : chart.GetHighsInRange(2))
    //     std::cout << x << " : ";
    // std::cout << std::endl;
    double highma = TI::sma(chart, 2, chart.GetHighsInRange(2));
    double lowma = TI::sma(chart, 2, chart.GetLowsInRange(2));

    if (nextTrend == 1) {
        maxLowPrice = std::max(lowPrice, maxLowPrice);

        if (highma < maxLowPrice && chart.GetPriceAt(0) < chart.GetLowAt(1)) {
            trend = 1;
            nextTrend = 0;
            minHighPrice = highPrice;
        }
    } else {
        minHighPrice = std::min(highPrice, minHighPrice);

        if (lowma > minHighPrice && chart.GetPriceAt(0) > chart.GetHighAt(1)) {
            trend = 0;
            nextTrend = 1;
            maxLowPrice = lowPrice;
        }
    }

    if (trend == 0) {
        if (prevTrend != 0) {
            up = prevDown;
            arrowUp = up - atr2;
        } else
            std::max(maxLowPrice, prevUp);
        atrHigh = up + dev;
        atrLow = up - dev;
    } else {
        if (prevTrend != 1) {
            down = prevUp;
            arrowDown = down + atr2;
        } else
            down = std::min(minHighPrice, prevDown);
        atrHigh = down + dev;
        atrLow = down - dev;
    }

    buySignal = (nextTrend != 0);
    sellSignal = (nextTrend == 0);

    // std::cout << " MaxLowPrice: " << maxLowPrice << " minHighPrice: " << minHighPrice << " lowma: " << lowma << " highma: " << highma <<  " lowPrice: " << lowPrice  << " highPrice: " << highPrice << std::endl;
    // std::cout << " trend: " << trend << " nextTrend: " << nextTrend << std::endl;
    
    // TI::rma(chart, 100);
    // std::cout << " rma: " << TI::rma(chart, 100) << std::endl;

    double percentChange = (chart.GetPriceAt(0) - boughtPrice) / boughtPrice;
    double dayPercentChange = (dayInitBalance - getNetBalance(chart)) / dayInitBalance;

    if (percentChange >= STOPLOSS) {
        balance += chart.GetPriceAt(0) * shares;
        shares = 0.0;
        std::cout << "\t\tTrade Stoploss! Sold At: " << chart.GetPriceAt(0) << " Bal: " << balance << std::endl;
    }

    Series<double> chartSeries = chart.toSeries();
    
    std::cout << chartSeries[10] << "[10] ---- " << chartSeries << "[0]" << std::endl;
}

double TickerCallback::getNetBalance(Chart &chart) {
    if (balance != 0) return balance;
    return chart.GetPriceAt(0) * shares;
}
