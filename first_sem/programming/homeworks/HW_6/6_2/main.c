#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* func(int* i, double* n){
    n += *i;
    return n;
}
int main() {
    const int N = 10;
    int intV = 2;
    int* arr = malloc(N*sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < N; i++){
        arr[i] = rand() % 100;
    }
    int* ptr = func(&intV, arr);

    return 1;
}
