#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;
    int **p1=&p;//double pointer
    
    //Address 
    printf("%d\n",&a);//Address of a
    printf("%d\n",&p);//Address of p
    printf("%d\n",&p1);//Address of p1
    
    //Values
    printf("%d\n",a);//Value is 10
    printf("%d\n",p);//Value of p(pointer) is address of a
    printf("%d\n",p1);//Value of p1(pointer) is address of p(pointer)
    
    //Printing values through p1 (pointer)
    printf("%d\n",*p1);//derefrence p1 first time then it will exact value/content of p(pointer) or address of a 
    printf("%d\n",**p1);//derefrence p1 second time then it will exact value/content of a
    
    //Printing values through p (pointer)
    printf("%d\n",*p);
    return 0;
}

