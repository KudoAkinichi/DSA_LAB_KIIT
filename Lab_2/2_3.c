//WAP to represent a given sparse matrix in 3-tuple format using 2-D array.

#include <stdio.h>

void convertToSparse(int matrix[][100], int rows, int cols, int sparseArray[][3], int *num) {
    *num = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseArray[*num][0] = i;
                sparseArray[*num][1] = j;
                sparseArray[*num][2] = matrix[i][j];
                (*num)++;
            }
        }
    }
}

void printSparse(int sparseArray[][3], int num) {
    printf("Row\t Column\t Value\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t %d\t %d\n", sparseArray[i][0], sparseArray[i][1], sparseArray[i][2]);
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[100][100];
    printf("Enter the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sparseArray[rows * cols][3];
    int num;

    convertToSparse(matrix, rows, cols, sparseArray, &num);
    printf("Sparse matrix in 3-tuple format:\n");
    printSparse(sparseArray, num);

    return 0;
}