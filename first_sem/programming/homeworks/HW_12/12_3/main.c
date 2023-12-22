#include <stdio.h>
#include <math.h>

typedef enum {
    REAL,
    COMPLEX
} CoordType;

typedef struct {
    CoordType type;
    union {
        struct {
            double x;
            double y;
        } real;
        struct {
            double re;
            double im;
        } complex;
    } data;
} Pair;

double calculate_distance(Pair p);
Pair calculate_midpoint(Pair p);

int main() {
    Pair p;
    int type;

    printf("Выберите тип чисел (0 - вещественные, 1 - комплексные): ");
    scanf("%d", &type);

    if (type == 0) {
        p.type = REAL;
        printf("Введите координаты точки (x y): ");
        scanf("%lf %lf", &p.data.real.x, &p.data.real.y);
    } else if (type == 1) {
        p.type = COMPLEX;
        printf("Введите координаты точки (re im): ");
        scanf("%lf %lf", &p.data.complex.re, &p.data.complex.im);
    } else {
        printf("Некорректный тип чисел.\n");
        return 1;
    }

    double distance = calculate_distance(p);
    printf("Расстояние между точками: %.2lf\n", distance);

    Pair midpoint = calculate_midpoint(p);
    printf("Координаты середины отрезка: ");
    if (midpoint.type == REAL) {
        printf("(%.2lf, %.2lf)\n", midpoint.data.real.x, midpoint.data.real.y);
    } else if (midpoint.type == COMPLEX) {
        printf("(%.2lf, %.2lf)\n", midpoint.data.complex.re, midpoint.data.complex.im);
    }

    return 0;
}

double calculate_distance(Pair p) {
    if (p.type == REAL) {
        double dx = p.data.real.x;
        double dy = p.data.real.y;
        return sqrt(dx * dx + dy * dy);
    } else if (p.type == COMPLEX) {
        double re = p.data.complex.re;
        double im = p.data.complex.im;
        return sqrt(re * re + im * im);
    }

    return 0.0;
}

Pair calculate_midpoint(Pair p) {
    Pair midpoint;
    midpoint.type = p.type;

    if (p.type == REAL) {
        midpoint.data.real.x = p.data.real.x / 2.0;
        midpoint.data.real.y = p.data.real.y / 2.0;
    } else if (p.type == COMPLEX) {
        midpoint.data.complex.re = p.data.complex.re / 2.0;
        midpoint.data.complex.im = p.data.complex.im / 2.0;
    }

    return midpoint;
}
