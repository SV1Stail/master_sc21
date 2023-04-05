#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int input(int n, int a[n]);
void output(int n, int a[n]);
void booble_sort(int size, int array[size]);
int input_len_mas(int *n);

int main() {
    int n = 0;
    int *data = malloc(n * sizeof(int));
    if (input_len_mas(&n) == 1 || input(n, data) == 1) {
        printf("n/a");
    } else {
        booble_sort(n, data);
        output(n, data);
    }

    free(data);
    data = NULL;
    return 0;
}
int input_len_mas(int *n) {
    int scan, flag = 0;
    char c = '\n';
    scan = scanf("%d%c", n, &c);
    if (scan != 2 || (c != '\n' && c != ' ') || *n > MAX || *n <= 0) {
        flag = 1;
    }
    return flag;
}

int input(int n, int a[n]) {
    int scan, flag = 0;
    char c = '\n';
    for (int p = 0; p < n; p++) {
        scan = scanf("%d%c", &a[p], &c);
        if (scan != 2 || (c != '\n' && c != ' ') || n > MAX) {
            flag = 1;
        }
        if (p == n - 1 && c != '\n') {
            flag = 1;
        }
    }
    return flag;
}
//&& *n <= NMAX && *n > 0
void output(int n, int a[n]) {
    for (int i = 0; i < n; i++) printf(i == n - 1 ? "%d\n" : "%d ", a[i]);
}

void booble_sort(int size, int array[size]) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
