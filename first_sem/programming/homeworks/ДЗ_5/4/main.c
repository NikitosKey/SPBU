#include <stdio.h>

void rec_func(int* c, int n){
    if (n != 1) {
        *c+=1;
        if (n % 2 == 0)
            return rec_func(c, n / 2);
        else
            return rec_func(c, 3 * n + 1);
    } else
        return;
}
int main() {
    int n = 13;
    int res = 0;
    rec_func(&res, n);
    printf("%d\n", res);
    return 0;
}
