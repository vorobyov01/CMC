#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.c"

#define eps  1e-4
#define eps1 eps / 150
#define eps2 eps / 5

double root(double (*f)(double), double (*g)(double), double a, double b, double epsilon);
double integral(double (*f)(double), double a , double b, double epsilon);

int print_iters = 0;

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);
