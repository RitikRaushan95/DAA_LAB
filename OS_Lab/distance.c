#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

int main() {

    struct point Ppoint, Qpoint;
    struct point *P = &Ppoint;
    struct point *Q = &Qpoint;


    printf("Enter the point One values (x y): ");
    scanf("%d %d", &P->x, &P->y);

    printf("Enter the point Two values (x y): ");
    scanf("%d %d", &Q->x, &Q->y);

    double distance = sqrt(pow(Q->x - P->x, 2) + pow(Q->y - P->y, 2));
    printf("Distance between the points: %.2f\n", distance);

    return 0;
}

