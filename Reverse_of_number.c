//..reverse of number
#include<stdio.h>
int reverse(int num){
	int reverse=0;
	while(num!=0){
		reverse=reverse*10+num%10;
		num=num/10;
	}
	return reverse;
}
int main(){
	int num;
	printf("Enter your number: ");
	scanf("%d",&num);
	printf("Reveresed number: %d",reverse(num));
	return 0;
}
