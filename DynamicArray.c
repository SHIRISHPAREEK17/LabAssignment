//Dynamic array creation
#include<stdio.h>
#include <stdlib.h>
int main(){
	int n,i;
	printf("Enter Number: ");
	scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int) * n);
     

    for (i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i+1);
        scanf("%d", &arr[i]);
    }

   
    printf("Display Array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); 
    return 0;
}
