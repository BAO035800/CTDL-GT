#include <stdio.h>

void hoanDoi(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int phanTach(int arr[], int low, int high) {
    int pivot = arr[low];  // Ch?n pivot l� ph?n t? �?u ti�n
    int i = low + 1;
    int j = high;

    while (i <= j) {
        // T?m ph?n t? l?n h�n pivot t? b�n tr�i
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // T?m ph?n t? nh? h�n pivot t? b�n ph?i
        while (arr[j] > pivot) {
            j--;
        }

        // N?u i < j, �?i ch? c�c ph?n t? t?i i v� j
        if (i < j) {
            hoanDoi(arr, i, j);
        }
    }

    // �?t pivot v�o ��ng v? tr� c?a n�
    hoanDoi(arr, low, j);

    // Tr? v? ch? s? c?a pivot
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Ph�n t�ch m?ng v� t?m v? tr� ch�nh x�c c?a pivot
        int pivotIndex = phanTach(arr, low, high);

        // �? quy v?i c�c ph?n t? b�n tr�i v� b�n ph?i pivot
        quickSort(arr, low, pivotIndex - 1);  // Ph?n b�n tr�i c?a pivot
        quickSort(arr, pivotIndex + 1, high); // Ph?n b�n ph?i c?a pivot
    }
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 2, 5, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang truoc khi sap xep: \n");
    inMang(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep: \n");
    inMang(arr, n);

    return 0;
}

