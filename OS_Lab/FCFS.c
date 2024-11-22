#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int BT;
    int AT;
    int WT;
    int TAT;
};

void calculateWT(struct Process P[], int n) {
    P[0].WT = 0;
    for (int i = 1; i < n; i++) {
        P[i].WT = (P[i - 1].WT + P[i - 1].BT);
        if (P[i].WT < P[i].AT) {
            P[i].WT = P[i].AT - P[i - 1].AT;
        }
    }
}

void calculateTAT(struct Process P[], int n) {
    for (int i = 0; i < n; i++) {
        P[i].TAT = P[i].WT + P[i].BT;
    }
}

void displayProcesses(struct Process P[], int n) {
    float totalWT = 0, totalTAT = 0;

    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        totalWT += P[i].WT;
        totalTAT += P[i].TAT;
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].pid, P[i].AT, P[i].BT, P[i].WT, P[i].TAT);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *P = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        P[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &P[i].AT);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &P[i].BT);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].AT > P[j + 1].AT) {
                struct Process temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    calculateWaitingTime(P, n);
    calculateTAT(P, n);
    displayProcesses(P, n);

    free(P);

    return 0;
}
