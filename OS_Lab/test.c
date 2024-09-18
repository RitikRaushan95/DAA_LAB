#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int m, int n) {
    int mid = (m + n) / 2;
    int l1 = mid - m + 1;
    int l2 = n - mid;

    int* arr1 = (int*)malloc(l1 * sizeof(int));
    int* arr2 = (int*)malloc(l2 * sizeof(int));

    int x = m;
    for (int i = 0; i < l1; i++) {
        arr1[i] = arr[x++];
    }
    int y = mid + 1;
    for (int i = 0; i < l2; i++) {
        arr2[i] = arr[y++];
    }

    int i = 0, j = 0;
    int k = m;

    while (i < l1 && j < l2) {
        if (arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }

    while (i < l1) {
        arr[k++] = arr1[i++];
    }

    while (j < l2) {
        arr[k++] = arr2[j++];
    }
}

void Mergesort(int* arr, int low, int size) {
    int l=low;
    int h=size;
    if (l>=h) {
        return;
    }

    int mid = (l + h) / 2;

    Mergesort(arr, l, mid);
    Mergesort(arr, mid + 1, h);

    merge(arr, low, h);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Mergesort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
