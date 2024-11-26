#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jobSequencing(vector<int>& profits, vector<int>& deadlines) {
    int n = profits.size();
    vector<pair<int, int>> jobs;

    for (int i = 0; i < n; i++) {
        jobs.push_back({profits[i], deadlines[i]});
    }

    sort(jobs.rbegin(), jobs.rend());
    int maxDeadline = *max_element(deadlines.begin(), deadlines.end());
    vector<bool> slots(maxDeadline, false);
    int maxProfit = 0;

    for (auto& job : jobs) {
        for (int j = min(job.second - 1, maxDeadline - 1); j >= 0; j--) {
            if (!slots[j]) {
                slots[j] = true;
                maxProfit += job.first;
                break;
            }
        }
    }

    return maxProfit;
}

int main() {
    int n;

    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<int> profits(n), deadlines(n);

    cout << "Enter the profits and deadlines for each job (profit deadline):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> profits[i] >> deadlines[i];
    }

    int result = jobSequencing(profits, deadlines);

    cout << "The maximum profit is: " << result << endl;

    return 0;
}
