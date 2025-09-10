#include<stdio.h>
void move(char a,char b){
	printf("Disk %c to %c: \n",a,b);
}
void towerOfHanoi(int n,char s,char i,char d){
	if(n>0){
		towerOfHanoi(n-1,s,d,i);
		move(s,d);
		towerOfHanoi(n-1,i,s,d);
	}
}
int main(){
	towerOfHanoi(3,'A','B','C');
	return 0;
}
