#include <stdio.h>
#include <stdlib.h>

void mergesort(int t[], int k);

void printArray(int arr[], int size);

int main() {
    int data[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: \n");
    printArray(data, n);

    mergesort(data, n);

    printf("Sorted array: \n");
    printArray(data, n);

    return 0;
}

void mergesort(int t[], int k) {
    if (k > 1) {
        int m = k / 2;    
        int n = k - m;    
        
        int *u = (int *)malloc(m * sizeof(int));
        int *v = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < m; i++) u[i] = t[i];
        for (int i = 0; i < n; i++) v[i] = t[m + i];

        mergesort(u, m);
        mergesort(v, n);

        merge(u, m, v, n, t);

        free(u);
        free(v);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}