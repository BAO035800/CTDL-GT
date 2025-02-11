#include <stdio.h>

void hoanDoi(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int phanTach(int arr[], int low, int high) {
    int pivot = arr[low];  // Ch?n pivot là ph?n t? ð?u tiên
    int i = low + 1;
    int j = high;

    while (i <= j) {
        // T?m ph?n t? l?n hõn pivot t? bên trái
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // T?m ph?n t? nh? hõn pivot t? bên ph?i
        while (arr[j] > pivot) {
            j--;
        }

        // N?u i < j, ð?i ch? các ph?n t? t?i i và j
        if (i < j) {
            hoanDoi(arr, i, j);
        }
    }

    // Ð?t pivot vào ðúng v? trí c?a nó
    hoanDoi(arr, low, j);

    // Tr? v? ch? s? c?a pivot
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Phân tách m?ng và t?m v? trí chính xác c?a pivot
        int pivotIndex = phanTach(arr, low, high);

        // Ð? quy v?i các ph?n t? bên trái và bên ph?i pivot
        quickSort(arr, low, pivotIndex - 1);  // Ph?n bên trái c?a pivot
        quickSort(arr, pivotIndex + 1, high); // Ph?n bên ph?i c?a pivot
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

