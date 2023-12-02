//
// Created by Никита Морозов on 29.09.2023.
//

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

//Через рекурсию я догадался раньше почему-то.
u_int64_t rec(u_int64_t a, u_int64_t b){
    u_int64_t r = a % b;
    if (a % b == 0)
        return b;
    else if (a % b != 0 )
        return rec(b, r);
}

int main(void){
    setlocale(LC_ALL, "Rus");
    u_int64_t a, b, max, min;
    printf("Введите A > 0: ");

    scanf("%lld", &a);
    printf("Введите B > 0: ");

    scanf("%lld", &b);

    if (a > b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }
    printf("НОД (A, B) найденный рекурсией: %d\n", rec(max, min));

//    Решение через while
    u_int64_t r;

    while (true){
        r = max % min;
        if (r == 0) break;
        max = min;
        min = r;
    }

    printf("НОД (A, B) найденный циклом: %d\n", min);
}