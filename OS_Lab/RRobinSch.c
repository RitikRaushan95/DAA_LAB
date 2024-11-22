#include <stdio.h>
#include <stdlib.h>

struct P {
    int id, BT, AT, WT, TAT, remBT;
};

void RR(struct P* proc, int n, int TQ) {
    int t = 0, done = 0;

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remBT > 0) {
                if (proc[i].remBT > TQ) {
                    t += TQ;
                    proc[i].remBT -= TQ;
                } else {
                    t += proc[i].remBT;
                    proc[i].remBT = 0;
                    proc[i].WT = t - proc[i].BT - proc[i].AT;
                    proc[i].TAT = t - proc[i].AT;
                    done++;
                }
            }
        }
    }
}

void display(struct P* proc, int n) {
    float totalWT = 0, totalTAT = 0;

    printf("ID\tBT\tAT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        totalWT += proc[i].WT;
        totalTAT += proc[i].TAT;
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].BT, proc[i].AT, proc[i].WT, proc[i].TAT);
    }

    printf("\nAvg WT: %.2f\n", totalWT / n);
    printf("Avg TAT: %.2f\n", totalTAT / n);
}

int main() {
    int n, TQ;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct P* proc = (struct P*)malloc(n * sizeof(struct P));
    if (proc == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter BT and AT for Process %d: ", i + 1);
        scanf("%d %d", &proc[i].BT, &proc[i].AT);
        proc[i].remBT = proc[i].BT;
    }

    printf("Enter TQ: ");
    scanf("%d", &TQ);

    RR(proc, n, TQ);
    display(proc, n);

    free(proc);

    return 0;
}
