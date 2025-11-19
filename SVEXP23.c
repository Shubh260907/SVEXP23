#include <stdio.h> // For input/output

/**
 * @brief Finds the maximum profit from a single buy and sell transaction.
 * @param prices An array of prices for each day.
 * @param n The number of days (size of the array).
 * @return The maximum profit achievable, or 0 if no profit is possible.
 */
int findMaxProfit(int prices[], int n) {

    // If you have 0 or 1 day, you can't make a transaction.
    if (n <= 1) {
        return 0;
    }

    // Initialize 'minPriceSoFar' to the first day's price
    int minPriceSoFar = prices[0];
    // Initialize 'maxProfit' to 0
    int maxProfit = 0;

    // Loop through the prices starting from the second day (index 1)
    for (int i = 1; i < n; i++) {

        // Check for a new best day to buy
        // If the current price is lower than any we've seen,
        // this is our new best day to buy.
        if (prices[i] < minPriceSoFar) {
            minPriceSoFar = prices[i];
        }

        // Check for a new best day to sell
        // If selling today (at prices[i]) gives a profit greater
        // than our current maxProfit, update maxProfit.
        else if (prices[i] - minPriceSoFar > maxProfit) {
            maxProfit = prices[i] - minPriceSoFar;
        }
    }

    // After checking all days, return the max profit found
    return maxProfit;
}

// --- Main function to run the test cases ---
int main() {

    // --- Test Case 1 ---
    int prices1[] = {20, 25, 15, 30, 10, 50};
    // sizeof(array) / sizeof(first_element) gives the array length
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Test Case 1: [20, 25, 15, 30, 10, 50]\n");
    printf("Profit: %d\n\n", findMaxProfit(prices1, n1));

    // --- Test Case 2 ---
    int prices2[] = {10, 8, 6, 4, 2};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Test Case 2: [10, 8, 6, 4, 2]\n");
    printf("Profit: %d\n\n", findMaxProfit(prices2, n2));

    // --- Test Case 3 ---
    int prices3[] = {100, 180, 260, 310, 40, 535, 695};
    int n3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("Test Case 3: [100, 180, 260, 310, 40, 535, 695]\n");
    printf("Profit: %d\n", findMaxProfit(prices3, n3));
    printf("Explanation: Buy on day 5 (price = 40) and sell on day 7 (price = 695). Profit = 695 - 40 = 655.\n\n");

    // --- Test Case 4 ---
    int prices4[] = {30, 20, 25, 40, 25, 50, 35};
    int n4 = sizeof(prices4) / sizeof(prices4[0]);
    printf("Test Case 4: [30, 20, 25, 40, 25, 50, 35]\n");
    printf("Profit: %d\n", findMaxProfit(prices4, n4));
    printf("Explanation: Buy on day 2 (price = 20) and sell on day 6 (price = 50). Profit = 50 - 20 = 30.\n\n");

    // --- Test Case 5 ---
    int prices5[] = {5, 5, 5, 5, 5};
    int n5 = sizeof(prices5) / sizeof(prices5[0]);
    printf("Test Case 5: [5, 5, 5, 5, 5]\n");
    printf("Profit: %d\n\n", findMaxProfit(prices5, n5));

    return 0;
}
