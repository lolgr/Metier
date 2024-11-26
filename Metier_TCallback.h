#pragma once
#include "Metier_Chart.h"

class TickerCallback {
    
    private:
        double STOPLOSS = -0.008; //Percent loss (0.8%)
        double DAYSTOPLOSS = -0.0035; //Percent loss (0.35%)

        double balance = 1018.95;
        double dayInitBalance = balance;

        // double gBalance = 1000.0;
        double boughtPrice = -1;
        double shares = 0.0;
        bool buySignal = false;
        bool sellSignal = false;        

    public:
        //Strategy by KivancOzbilgic 
        //  https://www.tradingview.com/script/kv8N05R7-AlphaTrend-Screener/
        
        void OnClose(Chart &chart);

        void OnOpen(Chart &chart);

        double getNetBalance(Chart &chart);

};