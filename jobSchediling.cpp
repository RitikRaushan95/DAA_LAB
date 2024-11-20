#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> &jobs, int n) {
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<int> result(maxDeadline + 1, -1);
    int totalProfit = 0;
    int countJobs = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (result[j] == -1) {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != -1) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {{1, 7, 15}, {2, 2, 20}, {3, 5, 30}, {4, 3, 18},{5, 4, 18}, {6, 5, 10},{7, 2, 23},{8, 7, 16},{9, 3, 25}};

    int n = jobs.size();
    jobScheduling(jobs, n);

    return 0;
}
