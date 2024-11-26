#include <iostream>
#include <sstream>
#include <string>
#include "json.h"

#include "Metier_app.h"
#include "Metier_CurlWrapper.h"
#include "Metier_Ticker.h"
#include "Metier_TCallback.h" 
using json = nlohmann::json;

int main(int argc, char* argv[]) {
    Chart chart;
    Ticker ticker(chart);

    TickerCallback callback;
    ticker.Initialize(callback);

    ticker.Run();
    
    return 0;
}