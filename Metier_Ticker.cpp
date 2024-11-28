#include <string>
#include "time.h"
#include <iomanip>
#include <unistd.h> 
#include <typeinfo>

#include "Metier_Ticker.h"
#include "Metier_TCallback.h"
#include "Metier_Chart.h"
#include "json.h"
using json = nlohmann::json;

void Ticker::Initialize(TickerCallback& callback) {
    gCallback = callback;

    auto Klines = RequestJson(MAXHISTORY);
    Bar prev = FormatJson(Klines.front());

    for (json::iterator it = Klines.begin(); it != Klines.end(); ++it) {
        Bar current = FormatJson(*it);
        if (!CompareBars(prev, current))
            gChart.AddBar(FormatBar((*it)));
    }
    
    //Need to Refactor
    auto prevDayBars = RequestJson(2, "1d");
    gChart.SetDayBarAt(0, FormatBar(prevDayBars[0]));
    gChart.SetDayBarAt(1, FormatBar(prevDayBars[1]));
    //-----------------
}

bool Ticker::CompareBars(Bar a, Bar b) {
    if (a.low != b.low) return false;
    if (a.high != b.high) return false;
    if (a.close != b.close) return false;
    if (a.volume != b.volume) return false;
    return true;
}

void Ticker::Run() {
    time_t prevTime = time(NULL);
    CurlRequest client;

    long prevKLineOT = RequestJson()[0][0];
    bool newBar = false;

    //Initialize wasn't called.
    if (gChart.GetBarCount() < 1) { std::cout << "Error Initialize wasn't called!" << std::endl; return; }
        
    while (true) {
        //Waits for 61 seconds
        if (time(NULL) >= (prevKLineOT / 1000) + 61)
            newBar = true;
        else if (time(NULL) - prevTime < 3)
            continue;
        prevTime = time(NULL);
        
        auto klines = RequestJson(2);
        auto kline = newBar ? klines[0] : klines[1];
        
        Bar bar = FormatJson(kline);
        
        if (newBar) {
            newBar = false;
            gChart.AddBar(bar);
            gCallback.OnClose(gChart);

            std::cout << "NEW BAR at " << bar.close << std::endl;
            
            prevKLineOT = static_cast<long>(kline[6]) + 1;

            //Need to Refactor
            auto prevDayBars = RequestJson(2, "1d");
            gChart.SetDayBarAt(0, FormatBar(prevDayBars[0]));
            gChart.SetDayBarAt(1, FormatBar(prevDayBars[1]));
            //-----------------
        } 
        else {
            gChart.SetBarAt(0, bar);
            gCallback.OnOpen(gChart);
        }
    }
}