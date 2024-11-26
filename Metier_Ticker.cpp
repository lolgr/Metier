#include <string>
#include "time.h"
#include <iomanip>
#include <unistd.h> 
#include <typeinfo>

#include "Metier_Ticker.h"
#include "Metier_CurlWrapper.h"
#include "Metier_TCallback.h"
#include "json.h"
using json = nlohmann::json;

void Ticker::Initialize(TickerCallback& callback) {
    CurlRequest client;
    gCallback = callback;
    auto Klines = json::parse(client.Get(APIURL + "/klines?limit=" + std::to_string(MAXHISTORY) + "&interval=" + INTERVAL + "&symbol=" + SYMBOL));
    for (json::iterator it = Klines.begin(); it != Klines.end(); ++it)
        gChart.AddBar(FormatBar((*it)));
    auto prevDayBars = json::parse(client.Get(APIURL + "/klines?limit=2&interval=1d&symbol=" + SYMBOL));
    for (int x = 0; x < 2; x++)
        gChart.SetDayBarAt(x, FormatBar(prevDayBars[x]));
}

void Ticker::Run() {
    time_t prevTime = time(NULL);
    CurlRequest client;
    long prevKLineOT = json::parse(client.Get(APIURL + "/klines?limit=1&interval=" + INTERVAL + "&symbol=" + SYMBOL))[0][0];
    bool newBar = false;
    int barCount = gChart.GetBarCount();
    if (barCount < 1)
        return; //Initialize wasn't called.
        
    while (true) {
        if (time(NULL) >= (prevKLineOT / 1000) + 61)
            newBar = true;
        else if (time(NULL) - prevTime < 3)
            continue;
        prevTime = time(NULL);
        
        auto klines = json::parse(client.Get(APIURL + "/klines?limit=2&interval=" + INTERVAL + "&symbol=" + SYMBOL));
        auto kline = newBar ? klines[0] : klines[1];
        
        std::array<double, 9> bar = FormatBar(kline);
        
        if (newBar) {
            // if (bar[0] != gChart.GetBarAt(0).value()[0])
            
            gChart.AddBar(bar);
            std::cout << "NEW BAR at " << bar[4] << std::endl;
            barCount += 1;
            gCallback.OnClose(gChart);
            prevKLineOT = bar[6] + 1;
            newBar = false;

            auto prevDayBars = json::parse(client.Get(APIURL + "/klines?limit=2&interval=1d&symbol=" + SYMBOL));
            for (int x = 0; x < 2; x++)
                gChart.SetDayBarAt(x, FormatBar(prevDayBars[x]));
        }
        else
        {
            // if (bar[0] != gChart.GetBarAt(0).value()[0])
            //     continue;
            gChart.SetBarAt(0, bar, barCount);
            gCallback.OnOpen(gChart);
        }
    }
}