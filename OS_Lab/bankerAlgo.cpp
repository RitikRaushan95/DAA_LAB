#include <iostream>
#include <vector>
using namespace std;

bool isSafeState(int n, int m, vector<vector<int>>& max, vector<vector<int>>& allot, vector<int>& avail) {
    vector<vector<int>> need(n, vector<int>(m));
    vector<bool> finish(n, false);
    vector<int> work(avail);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                // Check if all needs can be satisfied with available resources
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Allocate resources to the process
                    for (int j = 0; j < m; j++) {
                        work[j] += allot[i][j]; // Add allocated resources back to work
                    }
                    finish[i] = true;
                    count++;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "System is not in a safe state!" << endl;
            return false;
        }
    }

    cout << "System is in a safe state!" << endl;
    return true;
}

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resource types: ";
    cin >> m;

    vector<vector<int>> max(n, vector<int>(m)), allot(n, vector<int>(m));
    vector<int> avail(m);

    cout << "Enter the maximum demand matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            cin >> allot[i][j];
        }
    }

    cout << "Enter the available resources vector: ";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    isSafeState(n, m, max, allot, avail);

    return 0;
}
