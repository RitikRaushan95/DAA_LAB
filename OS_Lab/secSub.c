#include<stdio.h>
#include<math.h>

int main() {
    char name[5];
    char arr[10];
    
    printf("Enter the name: ");
    scanf("%s", name);
    
    printf("Entered name is: %s\n", name);
    
    printf("Enter 10 characters:\n");
    for(int i = 0; i < 10; i++) {
        scanf(" %c", &arr[i]);
    }
    
    printf("Entered array is: ");
    for(int i = 0; i < 10; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    
    int first = -1, last = -1;

    for(int i = 0; i<10; i++) {
        int j;
        for(j = 0; j < 5; j++) {
            if(arr[i + j] != name[j]) {
                break;
            }
        }
        if(j == 5) {
            first = i;
            last = i + j - 1;
            break; 
        }
    }

    if(first != -1) {
        printf("The substring was found from %d to %d in the array.\n", first, last);
    } else {
        printf("The substring was not found.\n");
    }
    
    return 0;
}
