#include <stdio.h>

void gnomeSort(int arr[], int n) {
    int index = 0;
    while (index < n) {
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } else {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

int main() {
    int arr[] = {9, 5, 7, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Исходный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    gnomeSort(arr, n);
    
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}