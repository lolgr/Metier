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
    // std::cout << "called" << std::endl;
    // alphaTrend3 = alphaTrend2;
    // alphaTrend2 = alphaTrend1;
    // alphaTrend1 = alphaTrend0;
    if (gBuySignal && gShares == 0.0) {
        gShares = gBalance / chart.GetPriceAt(0);
        gBalance -= chart.GetPriceAt(0) * gShares;
        std::cout << "\t\tBought At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    }
    else if (gSellSignal && gShares > 0.0) {
        gBalance += chart.GetPriceAt(0) * gShares;
        gShares = 0.0;
        std::cout << "\t\tSold At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    }

    prevTrend = trend;
    prevUp = up;
    prevDown = down;
}

void TickerCallback::OnOpen(Chart &chart) {
    // int AP = 14;
    // double coeff = 1.0;
    // bool novolumedata = false;

    // TI ti;
    // std::vector<double> trOut;
    // double tr = ti.tr(chart, trOut, AP);
    // double ATR = TI::sma(chart, AP, trOut);

    // double upT = chart.GetLowAt(0) - ATR * coeff;
    // double downT = chart.GetHighAt(0) + ATR * coeff;

    // double mfi = TI::mfi(chart, AP, ti.hlc3(chart, AP));

    // alphaTrend0 = (mfi >= 50 ? (upT < alphaTrend1 ? alphaTrend1 : upT) : (downT > alphaTrend1 ? alphaTrend1 : downT));
    // double volume = chart.GetBarAt(0).value()[5];

    // std::cout << chart.GetPriceAt(0) << std::endl;
    // std::cout << "upT: " << upT << "  -downT: " << downT << std::endl;

    // bool buySignal = alphaTrend0 > alphaTrend2 && alphaTrend3 <= alphaTrend2;
    // bool sellSignal = alphaTrend0 < alphaTrend2 && alphaTrend3 >= alphaTrend2;
    // if (buySignal && gShares == 0.0) {
    //     gShares = gBalance / chart.GetPriceAt(0);
    //     gBalance -= chart.GetPriceAt(0) * gShares;
    //     std::cout << "\t\tBought At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    // }
    // else if (sellSignal && gShares > 0.0) {
    //     gBalance += chart.GetPriceAt(0) * gShares;
    //     gShares = 0.0;
    //     std::cout << "\t\tSold At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    // }

    //---------------------------------------------------------------------------------


    // var int trend = 0
    // var int nextTrend = 0
    // var float maxLowPrice = nz(low[1], low)
    // var float minHighPrice = nz(high[1], high)




    int nextTrend = 0;
    double maxLowPrice = chart.GetLowAt(1);
    double minHighPrice = chart.GetHighAt(1);

    // var float up = 0.0
    // var float down = 0.0
    // float atrHigh = 0.0
    // float atrLow = 0.0
    // float arrowUp = na
    // float arrowDown = na



    double atrHigh = 0.0;
    double atrLow = 0.0;
    double arrowUp = 0.0;
    double arrowDown = 0.0;

    // atr2 = atr(100) / 2
    // dev = channelDeviation * atr2

    // double atr2 = TI::sma(chart, 100) / 2;
    double atr2 = 0;
    double dev = 2 * atr2;

    // highPrice = high[abs(highestbars(amplitude))]
    // lowPrice = low[abs(lowestbars(amplitude))]
    // highma = sma(high, amplitude)
    // lowma = sma(low, amplitude)

    double highPrice = chart.GetHighest(chart.GetHighsInRange(2));
    double lowPrice = chart.GetLowest(chart.GetLowsInRange(2));

    for(double x : chart.GetHighsInRange(2))
        std::cout << x << " : ";
    std::cout << std::endl;
    double highma = TI::sma(chart, 2, chart.GetHighsInRange(2));
    double lowma = TI::sma(chart, 2, chart.GetLowsInRange(2));

    // if nextTrend == 1
    // 	maxLowPrice := max(lowPrice, maxLowPrice)

    // 	if highma < maxLowPrice and close < nz(low[1], low)
    // 		trend := 1
    // 		nextTrend := 0
    // 		minHighPrice := highPrice
    // else
    // 	minHighPrice := min(highPrice, minHighPrice)

    if (nextTrend == 1) {
        maxLowPrice = std::max(lowPrice, maxLowPrice);
        // maxLowPrice = lowPrice > maxLowPrice ? lowPrice : maxLowPrice;

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
            // up = maxLowPrice > prevUp ? maxLowPrice : prevUp;
        atrHigh = up + dev;
        atrLow = up - dev;
    } else {
        if (prevTrend != 1) {
            down = prevUp;
            arrowDown = down + atr2;
        } else
            down = std::min(minHighPrice, prevDown);
            // down = minHighPrice < prevDown ? minHighPrice : prevDown;
        atrHigh = down + dev;
        atrLow = down - dev;
    }

    gBuySignal = (nextTrend != 0);
    gSellSignal = (nextTrend == 0);

    // buySignal = not na(arrowUp) and (trend == 0 and trend[1] == 1)
    // sellSignal = not na(arrowDown) and (trend == 1 and trend[1] == 0)

    std::cout << (gBuySignal ? "Upward Trend" : "Downward Trend") << std::endl;
    // std::cout << (trend == 0 ? up : down) << (trend == 0 ? " UP" : " Down") << " Trend: " << trend << std::endl;
    // std::cout << "atrHigh: " << atrHigh << " atrLow: " << atrLow << " atr2: " << atr2 << std::endl;
    // std::cout << " UP: " << up << " DOWN: " << down << std::endl;
    std::cout << " MaxLowPrice: " << maxLowPrice << " minHighPrice: " << minHighPrice << " lowma: " << lowma << " highma: " << highma <<  " lowPrice: " << lowPrice  << " highPrice: " << highPrice << std::endl;
    std::cout << " trend: " << trend << " nextTrend: " << nextTrend << std::endl;
    // TI::rma(chart, 100);

    // std::cout << " rma: " << TI::rma(chart, 100) << std::endl; 

    if ((gBoughtPrice - chart.GetPriceAt(0)) / gBoughtPrice >= STOPLOSS) {
        gBalance += chart.GetPriceAt(0) * gShares;
        gShares = 0.0;
        std::cout << "\t\tSold At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    }

    //---------------------------------------------------------------------------------

    /*
        Pi = 2 * asin(1)
        a1 = exp(-1.414* Pi / len)
        b1 = 2*a1*cos(1.414* Pi / len)
        c2 = b1
        c3 = (-a1)*a1
        c1 = 1 - c2 - c3
        v9 = 0.0
        v9 := c1*(src + nz(src[1])) / 2 + c2*nz(v9[1]) + c3*nz(v9[2])

    */

    // double len = 13 * 2;
    // double Pi = 2 * asin(1);
    // double a1 = pow(2.71828182, -1.414 * Pi / len);
    // double b1 = 2 * a1 * cos(1.414 * Pi / len);
    // double c2 = b1;
    // double c3 = (-a1) * a1;
    // double c1 = 1 - c2 - c3;
    // static double v90_1;
    // static double v91_1;
    // static double v92_1;
    // v92_1 = v91_1;
    // v91_1 = v90_1;
    // v90_1 = c1*(chart.GetPriceAt(0) + chart.GetPriceAt(1)) / 2 + c2*v91_1 + c3*v92_1;

    // len = 21 * 2;
    // Pi = 2 * asin(1);
    // a1 = pow(2.71828182, -1.414 * Pi / len);
    // b1 = 2 * a1 * cos(1.414 * Pi / len);
    // c2 = b1;
    // c3 = (-a1) * a1;
    // c1 = 1 - c2 - c3;
    // static double v90_2;
    // static double v91_2;
    // static double v92_2;
    // v92_2 = v91_2;
    // v91_2 = v90_2;
    // v90_2 = c1*(chart.GetPriceAt(0) + chart.GetPriceAt(1)) / 2 + c2*v91_2 + c3*v92_2;

    // std::cout << "13: " << v90_1 << (v90_1 < v90_2 ? " < " : " > ") << std::endl;
    // std::cout << "21: " << v90_2 << std::endl;
    
    // if (v90_1 > v90_2 && v91_1 < v91_2 && gShares == 0.0) {
    //     gShares = gBalance / chart.GetPriceAt(0);
    //     gBalance -= chart.GetPriceAt(0) * gShares;
    //     std::cout << "\t\tBought At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    // }
    // else if (v90_1 < v90_2 && v91_1 > v91_2 && gShares > 0.0) {
    //     gBalance += chart.GetPriceAt(0) * gShares;
    //     gShares = 0.0;
    //     std::cout << "\t\tSold At: " << chart.GetPriceAt(0) << " Bal: " << gBalance << std::endl;
    // }
}
