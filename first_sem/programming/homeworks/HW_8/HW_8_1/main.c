#include <stdio.h>
#include <stdlib.h>


int *recursion(int start, int N, int* result) {
    if (start > N)
        return result;
    if (start <= N) {
        result[0] += 1;
        result[1] += result[0] * result[0];
        recursion(start+1, N, result);
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int *res = (int *) malloc(2 * sizeof(int *));

    recursion(1, n, res);

    printf("%d %d", res[0], res[1]);

    return 0;
}
