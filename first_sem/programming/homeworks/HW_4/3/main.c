
#include <stdio.h>
#define n 3
int main() {
    const int m = 3;
    int arr[n][m];


    printf("Enter the matrix: \n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
        printf("New line:\n");
    }
    int sum = 0, k = 0;
    for(int i = 0; i < n; i++) {
        int j;
        for (j = m-1; j >= 0; j--) {
            if (arr[i][j] == 1){
                sum += j;
                k++;
                break;
            }
        }
        if (arr[i][j] != 1)
            sum--;
    }
    double sr = (double) sum / k;
    printf("Result: %lf", sr);
    return 0;
}


