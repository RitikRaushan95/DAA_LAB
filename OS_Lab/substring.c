#include<stdio.h>
#include<math.h>

int main() {
    char name[10];
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
    
    int j = 0;
    int first,last=0;
    for(int i = 0; i < 10; i++) {
        if(arr[i] == name[j]) { 
            if(j==1)first=i-1;
            j++;
        }
        last=i-j+1;
    }

    if(j > 0) {
        printf("The substring was found from %d to %d  in the array.\n", first, last);
    } else {
        printf("The substring was not found.\n");
    }
    
    return 0;
}
