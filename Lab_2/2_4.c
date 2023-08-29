#include <stdio.h>
#include <stdlib.h>

void nonZero(int **matr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Number of non-zero elements: %d\n", count);
}

void sumavgR(int **matr, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matr[i][j];
        }
        double average = (double)sum / n;
        printf("Sum of elements in row %d: %d, Average: %.2lf\n", i + 1, sum, average);
    }
}

void sumavgc(int **matr, int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matr[j][i];
        }
        double average = (double)sum / n;
        printf("Sum of elements in column %d: %d, Average: %.2lf\n", i + 1, sum, average);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int **matr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matr[i][j]);
        }
    }

    nonZero(matr, n);
    sumavgR(matr, n);
    sumavgc(matr, n);

    for (int i = 0; i < n; i++) {
        free(matr[i]);
    }
    free(matr);

    return 0;
}
