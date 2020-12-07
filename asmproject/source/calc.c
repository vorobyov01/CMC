extern int print_iters;

double integral(double (*f)(double), double a, double b, double eps2) {
    int n = 1;
    double x, dx;
    double sum = 0, oldsum = 0;
    do {
        oldsum = sum;
        sum = 0;
        n *= 2;
        x = a;
        dx = (b - a) / n;
        while (x < b) {
            sum += f(x) * dx;
            x += dx;
        }
    } while (fabs(sum - oldsum) > eps2);
    return sum;
}

double root(double (*f)(double), double (*g)(double), double a, double b, double eps1) {
    if (f(a) - g(a) > 0) {
        double t = a;
        a = b;
        b = t;
    }
    double x = (a + b) / 2;
    int iter = 0;
    double dy = f(x) - g(x);
    while (fabs(dy) > eps1) {
        if (dy < 0) {
            a = x;
        } else {
            b = x;
        }
        x = (a + b) / 2;
        dy = f(x) - g(x);
        iter += 1;
        if (iter > 100) break;
    }
    if (print_iters) {
        x = iter;
    }
    return x;
}

double f4(double x) {
    return log(x) + 2.0;
}
double f5(double x) {
    return -x + 5.0;
}
double f6(double x) {
    return sqrt(x);
}