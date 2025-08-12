
#include<stdio.h>
#define ROW 100
#define COL 100
int main()
{
	int m1[ROW][COL],m2[ROW][COL],m3[ROW][COL];
	int r1,c1,i,j,r2,c2;
	printf("enter row and column:");
	scanf("%d%d",&r1,&c1);
	//input of first matrix
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("enter value of[%d][%d]:",i,j);
			scanf("%d",&m1[i][j]);
		}
	}
        //input of matrix 2
	printf(" input of matrix 2:\n");
	printf("enter row and column:");
	scanf("%d%d",&r2,&c2);
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("enter value of[%d][%d]:",i,j);
			scanf("%d",&m2[i][j]);
		}
	}
	 //condition check
	if(r1!=r2||c1!=c2)
	{
		printf("error row and column are not same :");
		exit(1);
	}
	//logic of minus of two matrix
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			m3[i][j]=m1[i][j]-m2[i][j];
		}
		printf("\n");
	}
	printf("output of matrix 3 of sum 1+2:\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",m3[i][j]);
		}
		printf("\n");
	}
}
