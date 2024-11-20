#include <stdio.h>

struct Process {
    int id;
    int bt;
    int wt;
    int tat;
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i-1].wt + proc[i-1].bt;
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void sortProcessesByBurstTime(struct Process proc[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc[i].bt > proc[j].bt) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void findAverageTime(struct Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);

    int total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    struct Process proc[] = {{1, 6, 0, 0}, {2, 8, 0, 0}, {3, 7, 0, 0}, {4, 3, 0, 0}};
    int n = sizeof(proc) / sizeof(proc[0]);

    sortProcessesByBurstTime(proc, n);
    findAverageTime(proc, n);

    return 0;
}
