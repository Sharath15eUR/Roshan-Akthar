#include <stdio.h>
#include <stdlib.h>

void getmatrixvalues(int row, int col, int *arr) {
    for (int i = 0; i < row * col; i++) {
        if (scanf("%d", arr + i) != 1) {
            printf("Invalid Input\n");
            exit(0);
        }
    }
}

void printmatrixvalues(int row, int col, int *arr) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(arr + i * col + j));
        }
        printf("\n");
    }
}

void productofmatrix(int *matrix1, int *matrix2, int *prod, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(prod + i * col + j) = 0;
            for (int k = 0; k < col; k++) {
                *(prod + i * col + j) += *(matrix1 + i * col + k) * *(matrix2 + k * col + j);
            }
        }
    }
}

int main() {
    int row, col;

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &col);

    printf("Enter Values for Matrix 1:\n");
    int matrix1[row][col];

    getmatrixvalues(row, col, *matrix1);

    printf("Matrix 1:\n");
    printmatrixvalues(row, col, *matrix1);

    printf("Enter Values for Matrix 2:\n");
    int matrix2[row][col];

    getmatrixvalues(row, col, *matrix2);

    printf("Matrix 2:\n");
    printmatrixvalues(row, col, *matrix2);

    printf("The product is:\n");
    int prod[row][col];
    productofmatrix(*matrix1, *matrix2, *prod, row, col);
    printmatrixvalues(row, col, *prod);

    return 0;
}
