#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Process {
    int id;
    int bt;
    int at;
    int ct;
    int wt;
    int tat;
};

void findCompletionTime(vector<Process>& arr, int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        currentTime = max(currentTime, arr[i].at);
        arr[i].ct = currentTime + arr[i].bt;
        currentTime = arr[i].ct;
    }
}

void findTurnaroundTimeAndWaitingTime(vector<Process>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
    }
}

void sortProcessesByArrivalTime(vector<Process>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].at > arr[j].at) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void findAverageTime(vector<Process>& arr, int n) {
    findCompletionTime(arr, n);
    findTurnaroundTimeAndWaitingTime(arr, n);

    int total_wt = 0, total_tat = 0;
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";

    for (int i = 0; i < n; i++) {
        total_wt += arr[i].wt;
        total_tat += arr[i].tat;
        cout << arr[i].id << "\t" << arr[i].at << "\t\t" << arr[i].bt << "\t\t" << arr[i].ct << "\t\t"
             << arr[i].wt << "\t\t" << arr[i].tat << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time = " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time = " << (float)total_tat / n << "\n";
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID, Burst Time, and Arrival Time for process " << i + 1 << ": ";
        cin >> arr[i].id >> arr[i].bt >> arr[i].at;
    }

    sortProcessesByArrivalTime(arr, n);
    findAverageTime(arr, n);

    return 0;
}
