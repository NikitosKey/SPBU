//
// Created by Никита Морозов on 02.10.2023.
//

#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1 / (x*x - x + 1);
}

void plot_graph(double a, double b, int n) {
    double h = (b - a) / n;

    int num_rows = 40;  // Количество строк графика
    double min_y = INFINITY;
    double max_y = -INFINITY;

//    Находим минимальное и максимальное значение функции на заданном отрезке
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double y = f(x);
        if (y < min_y)
            min_y = y;
        if (y > max_y)
            max_y = y;
    }

    for (int row = num_rows; row >= 0; row--) {
        for (int i = 0; i <= n; i++) {
            double x = a + i * h;
            double y = f(x);

            int y_row = (int)((y - min_y) * 10);

            if (y_row == row) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    double a = -1.0;
    double b = 3.0;
    int n = 40;

    plot_graph(a, b, n);

    return 0;
}
