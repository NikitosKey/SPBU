#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMN 10
#define ROW 10

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void func(int** m, int* v){

    for (int i = 0; i < (ROW/2); i++) {
        for (int j = 0; j < COLUMN; j++)
            swap(&m[i][j], &m[(ROW/2) + i][j]);
    }
    for(int i = 0; i < ROW; i++)
            v[i] = m[i][i];
}


void print_matrix(int** m){
    printf("Matrix: \n ");
    for(int i = 0; i < ROW; i++){
        printf("\n");
        for(int j = 0; j < COLUMN ; j++)
            printf("%d ", m[i][j]);
    }
    printf("\n");
}

void fill_rand_m(int** m){

    for(int i = 0; i < ROW; i++ ){
        for(int j = 0; j < COLUMN; j++){
            m[i][j] = rand() % 100;
        }
    }
}

void print_vector(int* vec){
    printf("Vector: \n");
    for (int i = 0; i < ROW; i++)
        printf("%d ", vec[i]);
}


int main() {
    srand(time(NULL));
    int* vector = (int*) malloc(ROW * sizeof(int));
    int** matrix = (int**) malloc(ROW * sizeof(int *));

    for (int i = 0; i < COLUMN; i++)
        matrix[i] = (int*) malloc(COLUMN * sizeof(int));
    fill_rand_m(matrix);
    print_matrix(matrix);

    func(matrix, vector);

    print_matrix(matrix);
    //print_vector(vector);
    int sum = 0;

    for (int i = 0; i < ROW; i++){
        sum += vector[i];
    }

    printf("Sum = %d", sum);

/*    for (int i = 0; i < COLUMN; i++)
        free(matrix[i]);
    free(matrix);*/

    return 0;
}
