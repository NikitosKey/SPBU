#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void* a, const void* b){
    return *(int*)a > *(int*)b;
}

void binary_search(int* arr, int start, int end, int search_val){
    int mid = arr[(end + start)/2];
    if (end - start > 1){
        if (search_val > mid) binary_search(arr, (end + start)/2, end, search_val);
        if (search_val < mid) binary_search(arr, start, (end + start)/2, search_val);
    }
    if (search_val == mid) printf("Found\n");

}

void fill_rand_arr(int* arr, int arr_size){
    srand(time(NULL));
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % (10 * (1 + rand() % 20));
}

int main(){
    int search_val;
    repeat:printf("Enter search value: ");
    scanf("%d", &search_val);
    int* array = (int*) malloc(1000*sizeof(int));
    fill_rand_arr(array, 1000);
    qsort(array, 1000, sizeof(int), compare);
    binary_search(array, 0, 999, search_val);
   // goto repeat;
}