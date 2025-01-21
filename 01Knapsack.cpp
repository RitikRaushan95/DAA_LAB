#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n = 4; // Number of items
    vector<int> values = {60, 100, 120, 90}; // Values of items
    vector<int> weights = {10, 20, 30, 25};  // Weights of items
    int W = 50; // Maximum weight capacity

    cout << "Maximum value in knapsack: " << knapsack(W, weights, values, n) << endl;

    return 0;
}
