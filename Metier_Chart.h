#pragma once
#include <vector>
#include <string>
#include <array>
#include <optional>

class Chart
{
    private:
        std::vector<std::array<double, 9>> Bars;
        std::array<std::array<double, 9>, 2> DayBars;

    public:
        //barsAway starts at 0, meaning Bars[0] is the newest bar while Bars[Bars.size() - 1] is the oldest.
        bool SetBarAt(int barsAway, std::array<double, 9> bar, int barCount = -1);

        std::optional<std::array<double, 9>> GetBarAt(int barsAway, int barCount = -1);

        double GetPriceAt(int barsAway, int barCount = -1);

        double GetLowest(std::vector<double> pricesIn);

        double GetHighest(std::vector<double> pricesIn);

        double GetHighestInRange(int length);

        double GetLowestInRange(int length);

        std::vector<double> GetPricesInRange(int barsAway);

        std::vector<double> GetHighsInRange(int barsAway);

        std::vector<double> GetLowsInRange(int barsAway);

        double GetLowAt(int barsAway) {
            return GetBarAt(barsAway).value()[3];
        }

        double GetHighAt(int barsAway) {
            return GetBarAt(barsAway).value()[2];
        }

        double GetDayHighAt(int daysAgo) {
            return GetDayBarAt(daysAgo)[2];
        }

        double GetDayLowAt(int daysAgo) {
            return GetDayBarAt(daysAgo)[3];
        }

        void AddBar(std::array<double, 9> bar) {
            Bars.push_back(bar);
        }

        std::array<double, 9> GetDayBarAt(int daysAgo) {
            return DayBars[1 - daysAgo];
        }

        void SetDayBarAt(int daysAgo, std::array<double, 9> bar) {
            DayBars[1 - daysAgo] = bar;
        }

        int GetBarCount() {
            return static_cast<int>(Bars.size());
        }

};
