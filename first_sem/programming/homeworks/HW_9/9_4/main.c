#include <stdio.h>
#include <math.h>
#include <stdbool.h>



double f(double x){
    return 3*x - 4 * log(x) - 5;
}

double f_(double x){
    return 3 - 4 / x;
}

/*double f__(double x){
    return 4/(x*x);
}

bool root_in_section(double left, double right, const double  Epsilon){
    bool pos_ = f_(left) > 0;
    bool pos__ = f__(left) > 0;
    for(double i = left; i <= right; i += Epsilon){
        if ((f_(i) > 0) != pos_ || (f__(i) > 0) != pos__)
            return false;
    }
    printf("This section haven\'t a root\n");
    return true;
}*/

double take_rand_point(double left, double right, const double Epsilon){
    for(double i = left; i <= right; i += Epsilon)
        if (f(i) * f_(i) > 0)
            return i;

}

double recurssion(const double Epsilon, double x_n_1){
    double x_n = x_n_1 - f(x_n_1) / f_(x_n_1);

    if (fabs(x_n - x_n_1) > Epsilon)
        return recurssion(Epsilon, x_n);
    else
        return x_n_1;
}

double Newtons_method(double left, double right, const double Epsilon){
/*    if (root_in_section(left, right, Epsilon) == false)
        return 1.0;*/
    return recurssion(Epsilon, take_rand_point(left, right, Epsilon));
}

int main() {
    const double Epsilon = 0.0001;
    const double right_border = 4.0;
    const double left_border = 2.0;

    printf("%lf", Newtons_method(left_border, right_border, Epsilon));


    return 0;
}
