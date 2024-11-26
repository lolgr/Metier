#include <vector>
#include <array>
#include <string>
#include <iostream>
#include "Metier_Chart.h"

//Technical Indicators
class TI {
    public:
        //Weighted Moving Average
        // ---Need to improve efficiency by using static variables and avoid looping each time.
        static double wma(Chart chart, int length, bool includeCurrent = true);

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