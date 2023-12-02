#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int max (int a, int b){
    if (a > b)
        return a;
    return b;
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_matrix(int** m, int row, int column){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void print_arr(int* arr, int N){
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void Get_max(int** arr, int* max_elements, int row, int column){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++){
            max_elements[j] = max(arr[i][j], max_elements[j]);
        }
    print_arr(max_elements, column);
}

void Get_index_from_max(int* arr, int* indexes, int left, int right){
    if (left < right){
        int r = right, l = left;
        int piv = arr[(l+r)/2];
        while (l <= r){
            while (arr[l] > piv) l++;
            while (arr[r] < piv) r--;
            if (l <= r){
                swap(&arr[l], &arr[r]);
                swap(&indexes[l], &indexes[r]);
                r--;
                l++;
            }
        }
        Get_index_from_max(arr, indexes, left, l-1);
        Get_index_from_max(arr, indexes, l, right);
    }
}






int main() {
    const int n = 5;
    const int m = 5;
    int row_size = m * sizeof(int*);

    int* arr_of_sorted_indexes = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) arr_of_sorted_indexes[i] = i;

    int* max_elements = (int*) malloc(row_size);

    int** matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < m; i++)
        matrix[i] = (int*) malloc(row_size);

    // fill the matrix
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 100;
    print_matrix(matrix, n, m);
    Get_max(matrix, max_elements, n, m);

    // sort the last row and get the position of the initial indexes in the sorted to sort the remaining rows
    Get_index_from_max(max_elements, arr_of_sorted_indexes, 0, m - 1);

    print_arr(max_elements, m);
    print_arr(arr_of_sorted_indexes, m);

    // arrange the elements of other rows according to the received indexes
    for (int i = 0; i < n-1; i++){
        int* new_row = (int*) malloc(row_size);
        memcpy(new_row, matrix[i], row_size);
        for (int j = 0; j < m; j++){
            int pos = arr_of_sorted_indexes[j];
            new_row[j] = matrix[i][pos];
        }
        free(matrix[i]);
        matrix[i] = (int*) malloc(row_size);
        memcpy(matrix[i], new_row, row_size);
        free(new_row);
    }

    print_matrix(matrix, n, m);


    return 0;
}
