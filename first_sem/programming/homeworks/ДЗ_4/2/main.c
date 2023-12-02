#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int* a, int* b){
    int n = *a;
    *a = *b;
    *b = n;
}

void Lomuto_Sort (int* arr, int begin, int end){
    if (begin < end){
        int resolve_element = arr[end];
        int i = (begin - 1);

        for (int j = begin; j <= end - 1; j++){
            if (arr[j] <= resolve_element && (i != end || j != end)){
                i++;
                swap (&arr[i], &arr[j]);
            }
        }

        swap (&arr[i + 1], &arr[end]);

        Lomuto_Sort (arr, begin, i);
        Lomuto_Sort (arr, i + 2, end);
    }
}


void printArray (int* arr, int size){
    int i;
    for (i = 0; i < size; i++)
        printf ("%d ", arr[i]);
    printf ("\n");
}


int main() {
    srand(time(NULL));
    const int n = 50;
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        arr[i] = 1 + rand() % 1000;
    }

    printf("Before sort:\n");

    printArray(arr, n);
    Lomuto_Sort(arr, 0, n-1);

    printf("After sort:\n");
    printArray(arr, n);

    int a = 134, b = 567;
    printf("Searching bad items\n");
    for (int i =0; i < n; i++){
        if (arr[i] > a && arr[i] < b) arr[i] = -1;
    }
    int i = 0, j = n-1;
    while (arr[i] != -1)
        i++;

    while (arr[j] != -1)
        j--;
    j++;
    while (j < n){
        swap(&arr[i], &arr[j]);
        i++;
        j++;
    }

    printArray(arr, n);

    printf("Deleting bad items\n");
    int del_size = j - i;
    int* arr2 = malloc((n-del_size)*sizeof(int));
    memcpy(arr2, arr, (n-del_size)*sizeof(int));
    free(arr);
    arr = malloc((n-del_size)*sizeof(int));
    memcpy(arr, arr2, (n-del_size)*sizeof(int));
    free(arr2);
    printArray(arr, n-del_size);

    printf("Filling zero\n");
    for(int i = 0; i < n-del_size; i++)
        arr[i] = 0;

    printArray(arr, n-del_size);

    return 0;
}
