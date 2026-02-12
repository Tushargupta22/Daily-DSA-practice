#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    // Edge case: if there are no prices or only one day, profit is 0
    if (prices.size() < 2) return 0;

    int minPrice = prices[0]; // Assume the first day is the best to buy
    int maxProfit = 0;        // Start with zero profit

    for (int i = 1; i < prices.size(); i++) {
        // 1. Update the lowest price found so far
        minPrice = min(minPrice, prices[i]);

        // 2. Calculate profit if we sold today and update maxProfit
        int currentProfit = prices[i] - minPrice;
        maxProfit = max(maxProfit, currentProfit);
    }

    return maxProfit;
}

int main() {
    vector<int> stockPrices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(stockPrices) << endl;
    return 0;
}
