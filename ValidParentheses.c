//STACK IMPLEMENTED USING STATIC ARRAY IN C
// Valid Parentheses
#include <stdio.h>
#include<string.h>
#define MAX 50

int top=-1;
char stack[MAX];


int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == MAX- 1;
}

//Push 
void push( char item) {
    if (isFull()) 
        printf("Stack Overflow!\n");
    
	else 
        stack[++top] = item;
        //printf("Inserted %c at Top\n", item);
    
}

// Pop
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
    } 
	else {
        //printf("Popped: %c\n", stack[top--]);
        top--;
    }
}

// Peek
char peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1;
    } 
	else {
        return stack[top];
    }
}
int isValidParentheses(char a[]) {
    int i;
    int valid = 1;

    
    top = -1;// Reset stack for each call

    for (i = 0; i < strlen(a); i++) {
        if (a[i] == '(') {
            push('(');
        } 
		else if (a[i] == ')') {
			
            if (isEmpty()) {  
                valid = 0;
                break;
            }
            pop();
        }
        
    }

    if (valid && isEmpty())
        return 1;   
        
    else
        return 0;  
        
}
int main() {
	char a[MAX];   
    printf("Enter String: ");
    scanf("%s",a);  
    if (isValidParentheses(a))
        printf("Valid Parentheses\n");
    else
        printf("Not Valid Parentheses\n");  
   return 0;
}


