#include <stdio.h>

void merge (int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort (int arr[], int n) {
    if(n < 2) {
        return;
    }
    int i;
    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (i = 0; i< mid; i++) {
        left[i] = arr[i];
    }

    for (i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}

int main() {
    int arr[] = {1, 4, 6, 2, 7, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    mergeSort(arr, n);

    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}