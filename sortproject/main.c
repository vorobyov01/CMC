#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define MAX_VALUE 10000

int abs64(int64_t a) {
    if (a < 0)
        return -a;
    else
        return a;
}

void print_arr(int64_t *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%.1lf ", (double)arr[i]);
    }
    printf("\n");
}

void check_array(int64_t *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (abs64(arr[i]) > abs64(arr[i+1])) {
            printf("Error of sort!\n");
            exit(0);
        }
    }
}

int64_t *generate_array(int n, int type) {
    int64_t *arr = NULL;
    arr = malloc(n * sizeof(int64_t));
    srand(time(NULL));
    if (type == 1) {
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
    } else if (type == 2) {
        for (int i = 0; i < n; i++) {
            arr[i] = n - 1 - i;
        }
    } else if (type == 3 || type == 4) {
        for (int i = 0; i < n; i++) {
            arr[i] = (rand() * rand() * rand() * rand() * rand());
        }
    } else {
        printf("Error of type!\n");
        exit(0);
    }
    return arr;
}

void selection_sort(int64_t *arr, int n, int *comps, int *swaps) {
    *comps = 0; *swaps = 0; // кол-во сравнений / перемещений
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            (*comps)++;
            if (abs64(arr[j]) < abs64(arr[min_index])) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int64_t tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
            (*swaps)++;
        }
    }
}

void shell_sort (int64_t *arr, int n, int *comps, int *swaps) {
    *comps = 0; *swaps = 0; // кол-во сравнений / перемещений
    int step, i, j, tmp;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            for (j = i - step; (*comps)++, j >= 0 && abs64(arr[j]) > abs64(arr[j + step]); j -= step) {
                (*swaps)++;
                tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
            }
        }
    }
}

void cmp (int n, int type) {
    int64_t *arr1 = NULL, *arr2 = NULL;
    arr1 = generate_array(n, type);
    arr2 = malloc(n * sizeof(int64_t));
    memcpy(arr2, arr1, n * sizeof(int64_t));
    int *comps = malloc(sizeof(int));
    int *swaps = malloc(sizeof(int));
    print_arr(arr1, n);
    selection_sort(arr1, n, comps, swaps);
    check_array(arr1, n);
    printf("Slect: max:%d | comps:%d | swaps:%d\n", n, *comps, *swaps);

    shell_sort(arr2, n, comps, swaps);
    check_array(arr2, n);
    printf("Shell: max:%d | comps:%d | swaps:%d\n", n, *comps, *swaps);
    print_arr(arr1, n);
    free(arr1);
    free(arr2);
}

int main() {
    for (int type = 1; type <= 4; ++type) {
        printf("type:%d\n", type);
        for (int i = MAX_VALUE; i <= MAX_VALUE; i *= 10) {
            cmp(i, type);
        }
        //srand(time(NULL));
    }
    return 0;
}