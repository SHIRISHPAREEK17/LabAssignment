#include <stdio.h>
#define SIZE 3
struct sparseMatrix {
    int row, col, val;
};
void transpose(struct sparseMatrix sm[] ,int n){
	int i;
	for(i=0;i<n;i++){
		int temp=sm[i].row;
		sm[i].row=sm[i].col;
		sm[i].col=temp;
	}
	
}
int main() {
    int n, i, j;
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
    
    int mat[SIZE][SIZE]  = {0};
    int matT[SIZE][SIZE] = {0};

   
    for (i = 0; i < n; i++)
        mat[sm[i].row][sm[i].col] = sm[i].val;

    printf("\nBefore transpose:\n");
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    /* transpose triplets */
    transpose(sm, n);

    /* transposed matrix */
    for (i = 0; i < n; i++)
        matT[sm[i].row][sm[i].col] = sm[i].val;

    printf("\nAfter transpose:\n");
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++)
            printf("%d ", matT[i][j]);
        printf("\n");
    }

    return 0;
}


