#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x){
    return sin(log(x)) - cos(log(x)) + 2 * log(x);
}


double hd_method(double left, double right, double Epsilon){
    double x_n = (left + right)/2;
    if (f(x_n) != 0){
        if((f(x_n+Epsilon) > 0) != (f(right) > 0)) {
            double x_n__1 = (right + x_n) / 2;
            if (fabs(x_n__1 - x_n) > Epsilon)
                return hd_method(x_n, right, Epsilon);
            else
                return x_n;
        }
        else if((f(left) > 0) != (f(x_n) > 0)){
            double x_n__1 = (left+x_n)/2;
            if (fabs(x_n__1 - x_n) > Epsilon)
                return hd_method(left, x_n, Epsilon);
            else
                return x_n;
        }
        else
            return x_n;
    }
    else
        return x_n;

}

int main() {
    double Epsilon = 0.0001;
    double right_border = 3.0;
    double left_border = 1.0;

    printf("%lf", hd_method(left_border, right_border, Epsilon));

    return 0;
}
