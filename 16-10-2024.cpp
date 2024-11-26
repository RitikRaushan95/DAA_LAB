#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double fractionalKnapsack(int W, vector<int>& values, vector<int>& weights) {
    int n = values.size();
    vector<pair<double, int>> ratioIndex;

    for (int i = 0; i < n; i++) {
        double ratio = (double)values[i] / weights[i];
        ratioIndex.push_back({ratio, i});
    }

    sort(ratioIndex.rbegin(), ratioIndex.rend());

    double maxValue = 0.0;

    for (auto a : ratioIndex) {
        int index = a.second;
        if (W >= weights[index]) {
            W -= weights[index];
            maxValue += values[index];
        } else {
            maxValue += values[index] * ((double)W / weights[index]);
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> values(n), weights(n);

    cout << "Enter the value and weight of each item (value weight):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double maxValue = fractionalKnapsack(W, values, weights);

    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}
