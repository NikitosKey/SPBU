#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_arr(int* arr, int N){
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int descending(int* arr, int l, int r){
    int piv = arr[(r+l)/2];
    while (l <= r) {
        while (arr[l] > piv) l++;
        while (arr[r] < piv) r--;
        if (l <= r){
            swap(&arr[r], &arr[l]);
            l++;
            r--;
        }
    }
    return l;
}

int ascending(int* arr, int l, int r){
    int piv = arr[(r+l)/2];
    while (l <= r) {
        while (arr[l] < piv) l++;
        while (arr[r] > piv) r--;
        if (l <= r){
            swap(&arr[r], &arr[l]);
            l++;
            r--;
        }
    }
    return l;
}
void Quick_sort(int* arr, int left, int right, char ascending_or_descending){
    int pos = 0;
    if (left < right){
        switch (ascending_or_descending) {
            case '+':
                pos = ascending(arr, left, right);
                break;
            case '-':
                pos = descending(arr, left, right);
                break;
        }
        Quick_sort(arr, left, pos - 1, ascending_or_descending);
        Quick_sort(arr, pos, right, ascending_or_descending);
    }
}

int main() {
    srand(time(NULL));
    const int N = 50;
    int size = N * sizeof(int);
    int* arr = malloc(size);
    for (int i = 0; i < N; i++){
        int znak = rand() % 2;
        arr[i] = rand();
        switch (znak) {
            case 0:
                arr[i] *= -1;
                break;
        }
    }

    print_arr(arr, N);
    
    Quick_sort(arr, 0, 49, '+');
    int pos = 0;
    if(arr[0] < 0) {
        while (arr[pos] < 0)
            pos++;
        pos--;
    }
    print_arr(arr, N);
    Quick_sort(arr, 0, pos, '-');
    print_arr(arr, N);

    return 0;
}
