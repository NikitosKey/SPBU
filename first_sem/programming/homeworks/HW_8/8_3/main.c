#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void fill_rand (int *arr, int arr_size){
//    srand(time(NULL));
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 100;
}

void print_arr (int *arr, int arr_size){
   for (int i = 0; i < arr_size; i++) 
      printf("%d ", arr[i]);
   printf("\n");
}

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int* func (const int *arr_2, const int* arr2_size, const int *arr_3, const int* arr_3_size){
    int result_len = min(*arr2_size, *arr_3_size);

    int* result = (int *) malloc( result_len * sizeof(int *));    
    
    for (int i = 0; i < result_len; i++)
        result[i] = arr_2[i] + arr_3[i];
  

    return result;
}

int* create (const int *arr, int arr_size, int *arr2, int* arr2_size, int *arr3, int* arr3_size, int* (*func_ptr) (const int*, const int*, const int*, const int*)){
    int* arr_2 = (int *) malloc(arr_size * sizeof(int));

    int* arr_3 = (int *) malloc(arr_size * sizeof(int));
    
    int it_1 = 0, it_2 = 0;
    for (int i = 0; i < arr_size; i++){
        if (arr[i] % 2 == 0) {
            arr_2[it_1] = arr[i];
            it_1++;
        }
        if (arr[i] % 3 == 0){
            arr_3[it_2] = arr[i];
            it_2++;
        }
    }

    *arr2_size = it_1;
    *arr3_size = it_2;

    arr2 = (int *) malloc(*arr2_size * sizeof(int));
    arr3 = (int *) malloc(*arr3_size * sizeof(int));
    memcpy(arr2, arr_2, *arr2_size * sizeof(int));
    memcpy(arr3, arr_3, *arr3_size * sizeof(int));
    free(arr_2); free(arr_3);

    print_arr(arr2, *arr2_size);
    print_arr(arr3, *arr3_size);

    return func_ptr(arr2, arr2_size, arr3, arr3_size);
}

int main() {
    int arr_size;
    scanf("%d", &arr_size);
    
    int *arr, *arr2 = NULL, *arr3 = NULL;

    arr = (int *) malloc(arr_size * sizeof(int));
    fill_rand(arr, arr_size);

    print_arr(arr, arr_size);

    int arr2_size, arr3_size;
    int* (*ptr) (const int*, const int*, const int*, const int*) = func;
    
    int* result = create(arr, arr_size, arr2, &arr2_size, arr3, &arr3_size, ptr);
    
    print_arr(result, min(arr2_size, arr3_size));
    return 0;
}
