#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int BT;
    int AT;
    int WT;
    int TAT;
    int priority;
};

void sortProcessesByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].WT = 0;
    for (int i = 1; i < n; i++) {
        processes[i].WT = (processes[i - 1].WT + processes[i - 1].BT);
        if (processes[i].WT < processes[i].AT) {
            processes[i].WT = processes[i].AT - processes[i - 1].AT;
        }
    }
}

void calculateTurnAroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].TAT = processes[i].WT + processes[i].BT;
    }
}

void displayProcesses(struct Process processes[], int n) {
    float totalWT = 0, totalTAT = 0;

    printf("PID\tPriority\tBurst\tArrival\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        totalWT += processes[i].WT;
        totalTAT += processes[i].TAT;
        printf("%d\t%d\t\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].priority, processes[i].BT, processes[i].AT, processes[i].WT, processes[i].TAT);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].BT);
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].AT);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    sortProcessesByPriority(processes, n);
    calculateWaitingTime(processes, n);
    calculateTurnAroundTime(processes, n);
    displayProcesses(processes, n);

    free(processes);

    return 0;
}
