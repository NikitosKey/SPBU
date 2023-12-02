#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"Rus");
     int n = 0;
     double res = 1, fac = 1;
    printf("N = ");
    scanf("%d", &n);

   for (int  i = 1; i < n; i++){
        fac *= i;
        res += fac;
    }
    printf("Результат: %lf", res);

}
