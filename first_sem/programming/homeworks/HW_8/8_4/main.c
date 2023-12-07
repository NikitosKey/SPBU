#include <stdio.h>
#include <stdarg.h>

double func(int n, ...){
    double sum = 0;
    int k = 0;
    va_list params;
    va_start(params, n);
    for(int i=0;i<n; i++){
        int m = va_arg(params, int);
        k+=m;
        for (int i = 0; i < m; i++)
            sum += va_arg(params, double);
    }
    va_end(params);
    return sum/(double) k;
}

int main(void){
    printf("%lf\n", func(2, 3, 1231.141, 12414.2323, 60.5, 2, 23.9, 1.000001));
}
