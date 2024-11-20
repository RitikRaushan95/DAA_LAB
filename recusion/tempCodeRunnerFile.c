#include<stdio.h>
int a=0;
void TOH(int n, char s, char h, char d) {
    if (n == 1) {
       a++;
        return;
    }
    TOH(n - 1, s, d, h);
    TOH(n - 1, d, h, s);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    TOH(n, 'S', 'H', 'D');
    return 0;
}
