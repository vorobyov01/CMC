#include "HEAD.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        char *arg1 = "roots";
        if (strcmp(arg1, argv[1]) == 0) {
            double root1 = root(&f1, &f3, -3.0, -2.0, eps1);
            double root2 = root(&f2, &f3, -1.0, 0.0, eps1);
            double root3 = root(&f1, &f2, 1.0, 2.0, eps1);
            printf("(%lf, %lf)\n", root1, f1(root1));
            printf("(%lf, %lf)\n", root2, f2(root2));
            printf("(%lf, %lf)\n", root3, f1(root3));
            exit(0);
        }
        char *arg = "help";
        if (strcmp(arg, argv[1]) == 0) {
            printf("You can:\n");
            printf("try \"help\" to repeat this message\n");
            printf("try \"roots\" to print roots\n");
            printf("try \"test\" to test functions\n");
            printf("try \"iters\" to print amount of iterations:\n");
            exit(0);
        }
        char *arg2 = "iters";
        if (strcmp(arg2, argv[1]) == 0) {
            print_iters = 1;
            printf("%lf\n", root(&f1, &f3, -3.0, -2.0, eps1));
            printf("%lf\n", root(&f2, &f3, -1.0, 0.0, eps1));
            printf("%lf\n", root(&f1, &f2, 1.0, 2.0, eps1));
            exit(0);
        }
        char *arg3 = "test";
        if (strcmp(arg3, argv[1]) == 0) {
            printf("root of ln(x) + 2 and sqrt(x): ");
            printf("%lf\n", root(&f4, &f6, 0, 1, eps1));
            printf("root of ln(x) + 2 and -x+5: ");
            printf("%lf\n", root(&f4, &f5, 2, 3, eps1));
            printf("root of -x+5 and sqrt(x): ");
            printf("%lf\n", root(&f5, &f6, 3, 4, eps1));
            
            printf("integral ln(x) + 2 from 1 to 3 = ");
            printf("%lf\n", integral(&f4, 1, 3, eps2));
            //printf("%lf %lf\n", f4(1), f4(3));
            printf("integral -x + 5 from -2 to 0 = ");
            printf("%lf\n", integral(&f5, -2, 0, eps2));
            printf("integral sqrt(x) from 5 to 5.5 = ");
            printf("%lf\n", integral(&f6, 5, 5.5, eps2));
            exit(0);
        }
    }
    double area = 0;
    double root1 = root(&f1, &f3, -3.0, -2.0, eps1);
    double root2 = root(&f2, &f3, -1.0, 0.0, eps1);
    double root3 = root(&f1, &f2, 1.0, 2.0, eps1);
    area += integral(&f3, root1, root2, eps2);
    area += integral(&f2, root2, root3, eps2);
    area -= integral(&f1, root1, root3, eps2);
    printf("Common area between graphs: ");
    printf("%lf\n", area);
    return 0;
}