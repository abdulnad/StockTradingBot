#include <iostream>
#include <vector>

class MovingAverageCrossoverBot
{
private:
    std::vector<double> prices;
    int shortTermPeriod;
    int longTermPeriod;

public:
    MovingAverageCrossoverBot(int shortTerm, int longTerm) : shortTermPeriod(shortTerm), longTermPeriod(longTerm) {}

    void addPrice(double price)
    {
        prices.push_back(price);
    }

    double calculateMovingAverage(int period)
    {
        int size = prices.size();
        if (size < period || period <= 0)
        {
            // Invalid period, return 0.0 or handle accordingly
            std::cerr << "Error: Invalid moving average period.\n";
            return 0.0;
        }

        double sum = 0.0;
        for (int i = size - period; i < size; ++i)
        {
            sum += prices[i];
        }

        return sum / period;
    }

    void executeTradingStrategy()
    {
        double shortTermMA = calculateMovingAverage(shortTermPeriod);
        double longTermMA = calculateMovingAverage(longTermPeriod);

        if (shortTermMA == 0.0 || longTermMA == 0.0)
        {
            // Error in calculating moving averages, exit without taking action
            std::cerr << "Error: Moving average calculation failed.\n";
            return;
        }

        // Check for crossover
        if (shortTermMA > longTermMA)
        {
            // Execute buy order
            std::cout << "Buy order executed.\n";
        }
        else if (shortTermMA < longTermMA)
        {
            // Execute sell order
            std::cout << "Sell order executed.\n";
        }
        else
        {
            // No action
            std::cout << "No action taken.\n";
        }
    }
};

int main()
{
    MovingAverageCrossoverBot tradingBot(10, 30);

    // Simulating price data
    tradingBot.addPrice(100.0);
    tradingBot.addPrice(105.0);
    tradingBot.addPrice(95.0);
    tradingBot.addPrice(110.0);

    // Execute trading strategy
    tradingBot.executeTradingStrategy();
    std::cout << "ok";

    return 0;
}