//
// Created by Никита Морозов on 30.09.2023.
//

#include <stdio.h>
#include <stdlib.h>

#define MOPS(x, y) (x = y * y)

#define POWER(a)\
if ((a) % 3 == 0){\
    int x = 1;\
    while(x < a){\
        x *= 3;\
        if (x > a){\
            printf("Error: Line %d, File %s\n", __LINE__, __FILE__);\
            exit(0);\
        }\
    }\
}\
else if (a == 1);\
else {\
    printf("Error: Line %d, File %s\n", __LINE__, __FILE__); \
    exit(0); \
}

int main(){
//    Part 1
    double a;
    double b;
    printf("Enter the double number: ");
    scanf("%lf", &a);
    printf("Enter the double number again: ");
    scanf("%lf", &b);

    printf("a and b before using MOPS: %lf, %lf\n", a, b);
    MOPS(a,b);
    printf("a and b after using MOPS: %lf, %lf\n", a, b);

//    Part 2
    int x, y;
    printf("Enter the number: ");
    scanf("%d", &x);
    printf("Enter the number again: ");
    scanf("%d", &y);

    POWER(x);
    POWER(y);
    printf("a and b are powers of 3.\n");
}