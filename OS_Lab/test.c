#include<stdio.h>

int main() {
    char name[10], arr[10];
    
    scanf("%s", name);
    
    for(int i = 0; i < 10; i++) {
        scanf(" %c", &arr[i]);
    }
    
    int j = 0, first = -1, last = -1;
    
    for(int i = 0; i < 10; i++) {
        if(arr[i] == name[j]) { 
            if(j == 1) first = i - 1;
            j++;
        }
        last = i - j + 1;
    }

    if(j > 0) {
        printf("Substring found from %d to %d\n", first, last);
    } else {
        printf("Substring not found.\n");
    }
    
    return 0;
}
