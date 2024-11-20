#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doesNameExist(char *name, char *charArray, int n) {
    int a = strlen(name);
    for (int i = 0; i <= n - a; i++) {
        int found = 1;
        for (int j = 0; j < a; j++) {
            if (charArray[i + j] != name[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char name[100];
    int n;

    printf("Enter the name to search: ");
    scanf("%s", name);

    printf("Enter the number of characters in the array: ");
    scanf("%d", &n);

    char *charArray = (char *)malloc(n * sizeof(char));

    if (charArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the characters in the array: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &charArray[i]);
    }

    if (doesNameExist(name, charArray, n)) {
        printf("The name exists in the array.\n");
    } else {
        printf("The name does not exist in the array.\n");
    }

    free(charArray);

    return 0;
}
