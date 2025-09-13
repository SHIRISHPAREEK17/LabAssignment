#include <stdio.h>
#define SIZE 10

int mat[SIZE][SIZE] = {0};

struct sparseMatrix {
    int row, col, val;
};
int main() {
    int n, i, j, k = 0;
    printf("Enter number of non-zero elements for matrix: ");
    scanf("%d", &n);    
    
	struct sparseMatrix sm[n];                 
    for (i = 0; i < n; i++) {            
        printf("Enter row %d: ", i + 1);
        scanf("%d", &sm[i].row);

        printf("Enter col %d: ", i + 1);
        scanf("%d", &sm[i].col);

        printf("Enter val %d: ", i + 1);
        scanf("%d", &sm[i].val);
    }
    
    for (i = 0; i < n; i++) {              
        mat[sm[i].row][sm[i].col] = sm[i].val;
    }
    
    for (i = 0; i < SIZE; i++) {           
        for (j = 0; j < SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

