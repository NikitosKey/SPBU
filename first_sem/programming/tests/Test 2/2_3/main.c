#include <stdio.h>

typedef double (*DoubleFunction)(double);

double evaluateFunctions(double x, DoubleFunction f, DoubleFunction g) {
    double result = f(x + g(x * x));
    return result;
}

double square(double x) {
    return x * x;
}

double addOne(double x) {
    return x + 1;
}

int main() {
    double x = 2.0;

    double result = evaluateFunctions(x, addOne, square);

    printf("Результат: %lf\n", result);

    return 0;
}
