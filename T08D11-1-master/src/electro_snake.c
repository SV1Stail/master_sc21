#include <stdio.h>
#include <stdlib.h>
int cols_and_lines(int *cols, int *lines);
void swap(int *a, int *b);

void sort_vertical(int **matrix, int row, int cols, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m);

int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);

int main() {
    int n = 0, m = 0;

    if (cols_and_lines(&n, &m) == 1) {
        printf("n/a");
    } else {
        // 1 mas///
        int **matrix = malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix[i] = malloc(m * sizeof(int));
        }
        // 2 mas///
        int **result = malloc(n * sizeof(int *) + n * m * sizeof(int));
        int *result_p = (int *)(result + n);
        for (int i = 0; i < n; i++) {
            result[i] = result_p + m * i;
        }

        if (input(matrix, n, m) == 1) {
            printf("n/a");
            for (int i = 0; i < n; i++) free(matrix[i]);
            free(matrix);
            free(result);
            free(result_p);
        } else {
            sort_vertical(matrix, n, m, result);
            output(result, n, m);
            printf("\n");
            sort_horizontal(matrix, n, m);
            output(matrix, n, m);
            for (int i = 0; i < n; i++) free(matrix[i]);
            free(matrix);
            free(result);
            free(result_p);
        }
        for (int i = 0; i < n; i++) free(matrix[i]);
        free(matrix);
        free(result);
        free(result_p);
    }

    return 0;
}

void sort_vertical(int **arr, int row, int cols, int **result_matrix) {
    int *sortArray = malloc(row * cols * sizeof(int));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            sortArray[i * cols + j] = arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < row; k++)
                for (int l = 0; l < cols; l++)
                    if (arr[i][j] < arr[k][l]) swap(&arr[i][j], &arr[k][l]);
    int counter;

    for (int j = 0; j < cols; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < row; i++) {
                result_matrix[i][j] = sortArray[j * row + i];
            }
        } else {
            counter = 0;

            for (int i = row - 1; i >= 0; i--) {
                result_matrix[i][j] = sortArray[j * row + counter];
                counter++;
            }
        }
    }
    free(sortArray);
}

void sort_horizontal(int **matrix, int n, int m) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1 || i == 1) {
            for (int j = 0; j < m / 2; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][m - j - 1];
                matrix[i][m - j - 1] = tmp;
            }
        }
    }
}

int cols_and_lines(int *cols, int *lines) {
    char ch, ch2;
    int flag = 0;
    if (scanf("%d%c", cols, &ch) != 2 || ch > 32 || *cols <= 0) {
        flag = 1;
    } else if (scanf("%d%c", lines, &ch2) != 2 || ch2 > 32 || *lines <= 0) {
        flag = 1;
    }
    return flag;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int input(int **matrix, int n, int m) {
    int i, j, flag = 0;
    char ch;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (scanf("%d%c", &matrix[i][j], &ch) != 2 || ch > 32) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < m; l++)
                    if (matrix[i][j] < matrix[k][l]) swap(&matrix[i][j], &matrix[k][l]);
    return flag;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
