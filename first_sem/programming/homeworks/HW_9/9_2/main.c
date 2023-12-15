#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double f(double x){
    return (-3.0 * sin(sqrt(x)))/0.35 + 3.8/0.35;
}

double f_(double x){
    return ((-3.0 * cos(sqrt(x)))/(2.0 * sqrt(x)))/0.35;
}

double it_sloving(double x_n, double Epsilon){
    double x_n_1 = x_n;
    x_n = f(x_n);
    if (fabs(x_n - x_n_1) > Epsilon)
        return it_sloving(x_n, Epsilon);
    else
        return x_n;
}

double finding_x_0(double left, double right, double Epsilon){
    double x_0;
    for (x_0 = left; x_0 <= right; x_0 += Epsilon){
        if (f_(x_0) < 1.0) break;
    }
    return x_0;
}

int main() {
    const double Epsilon = 0.0001;
    const double left_border = 2.0;
    const double right_border = 3.0;
    double x_0 = finding_x_0(left_border, right_border, Epsilon);

    printf("x = %lf", it_sloving(x_0, Epsilon));
    return 0;
}
