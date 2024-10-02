def max_profit(prices):
    # Initialize the minimum price as a very large value and max_profit as 0
    min_price = float('inf')
    max_profit = 0

    # Loop through each price in the array
    for price in prices:
        # Update the minimum price found so far
        if price < min_price:
            min_price = price
        # Calculate the profit if we sell at the current price, and update max_profit if it's greater than the previous max_profit
        elif price - min_price > max_profit:
            max_profit = price - min_price

    return max_profit

# Test cases
test_cases = [
    ([7, 1, 5, 3, 6, 4], 5),  # Buy on day 2, sell on day 5 (profit = 6 - 1 = 5)
    ([7, 6, 4, 3, 1], 0),      # No profitable transaction (prices continuously decrease)
    ([1, 2, 3, 4, 5], 4),      # Buy on day 1, sell on day 5 (profit = 5 - 1 = 4)
    ([3, 3, 3, 3, 3], 0),      # All prices are the same (no profit)
    ([2, 1, 2, 1, 2], 1),      # Buy on day 2, sell on day 3 (profit = 2 - 1 = 1)
]

# Running the test cases
for i, (prices, expected) in enumerate(test_cases, 1):
    result = max_profit(prices)
    print(f"Test case {i}: Expected {expected}, Got {result}, {'Pass' if result == expected else 'Fail'}")
