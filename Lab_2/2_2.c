//2.2 Write a program to perform the following operations on a given square matrix using functions: 
//i.   Find the no.of nonzero elements
//ii.  Display upper triangular matrix
//iii. Display the elements of just above and below the main diagonal

#include <stdio.h>


int countNonZeroElements(int matrix[][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}


void displayUpperTriangular(int matrix[][100], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d\t", matrix[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
}


void displayDiagonalElements(int matrix[][100], int n) {
    printf("Elements above main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                printf("%d\t", matrix[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }

    printf("Elements below main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                printf("%d\t", matrix[i][j]);
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix[100][100];
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix entered:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    int nonzeroCount = countNonZeroElements(matrix, n);
    printf("Number of nonzero elements: %d\n", nonzeroCount);

    displayUpperTriangular(matrix, n);

    displayDiagonalElements(matrix, n);

    return 0;
}