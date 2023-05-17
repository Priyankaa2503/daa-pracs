#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int start = low;
    int end = high;
    int pivot = arr[low];
    
    while (start < end) {
        while (arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&arr[start], &arr[end]);
        }
    }
    
    swap(&arr[low], &arr[end]);
    return end;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[] = {23, 47, 28, 79, 91, 45, 32, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting:\n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Array after sorting:\n");
    printArray(arr, n);
    return 0;
}
