# Pseudo Stock Trading bot

Hello,

Welcome to my short little project which involves a pseudo stock trading algorithm which represents a basic moving average crossover strategy.

The three main components of this algorithm are:

# 1. Moving Averages:

The bot calculates two moving averages over different periods: a short-term moving average (shortTermMA) and a long-term moving average (longTermMA).
Moving averages are used to smooth out price fluctuations and identify trends.

# 2. Crossover Signal:

The strategy generates a trading signal based on the relationship between the short-term and long-term moving averages.
When the short-term moving average crosses above the long-term moving average, it is considered a bullish signal, and a "Buy" order is executed.
Conversely, when the short-term moving average crosses below the long-term moving average, it is considered a bearish signal, and a "Sell" order is executed.

# 3. No Action:

If there is no crossover between the moving averages, the bot takes no action.
