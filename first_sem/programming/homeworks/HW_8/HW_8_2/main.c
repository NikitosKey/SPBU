#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(double* arr, int start, int end, double* result){
    int mid_num = (end + start)/2;
    if (start < end) {
        func(arr, start, mid_num, result);
        func(arr, mid_num+1, end, result);
    }
    if (start == end)
        *result *= arr[start] / (1 + start);
}


void print_arr(double* arr, int n){
    for (int i = 0; i < n; i++)
        printf("%lf ", arr[i]);
    printf("\n");
}


void fill_rand_arr (double *arr, int arr_size){
    srand(time(NULL));
    for (int i = 0; i < arr_size; i++)
        arr[i] = (double) (rand() % 100);
}


int main() {
    int n;
    scanf("%d", &n);
    double * arr = (double *) malloc(n * sizeof(double));

    fill_rand_arr(arr, n);

    print_arr(arr, n);

    double res = 1;
    func(arr, 0, n-1, &res);
    printf("%lf", res);

    return 0;
}
