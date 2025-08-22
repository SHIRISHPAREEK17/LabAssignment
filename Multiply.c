#include<stdio.h>
#include<stdlib.h>
int main() {
    int row1, row2, col1, col2;
    int m1[100][100], m2[100][100], m3[100][100];
    int i, j, k;

    printf("Enter rows for matrix 1: ");
    scanf("%d", &row1);
    printf("Enter cols for matrix 1: ");
    scanf("%d", &col1);
    printf("Enter rows for matrix 2: ");
    scanf("%d", &row2);
    printf("Enter cols for matrix 2: ");
    scanf("%d", &col2);

    if (col1 != row2) {
        printf("Column of matrix 1 is not equal to Row of matrix 2\n");
        exit(1);
    }

    // Input Matrix 1
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter value of m1[%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    // Input Matrix 2
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter value of m2[%d][%d]: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    // Matrix Multiplication
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            m3[i][j] = 0;  
            for (k = 0; k < col1; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Output
    printf("Matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }

    return 0;
}

