#include <stdio.h>
#include <math.h>
#define eps 1e-6

double f1(double);
double f2(double);

double root(double (*f)(double), double (*g)(double), double a, double b, double eps1) {
    if (f(a) - g(a) > 0) {
        double t = a;
        a = b;
        b = t;
    }
    double x = (a + b) / 2;
    int epoch = 0;
    double dy = f(x) - g(x);
    while (fabs(dy) > eps1) {
        if (dy < 0) {
            a = x;
        } else {
            b = x;
        }
        x = (a + b) / 2;
        dy = f(x) - g(x);
        epoch += 1;
        if (epoch > 100) break;
    }
    printf("%d\n", epoch);
    return x;
}

int main() {
	printf("%lf %lf\n", f1(1.252), f2(1.252));
	printf("%lf\n", root(&f1, &f2, 1.0, 2.0, eps));
}