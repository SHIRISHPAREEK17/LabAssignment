#include <stdio.h>
#include <string.h>
#define MAX 50

int top=-1;
char stack[MAX];

int isEmpty() { 
   return top == -1; 
}
int isFull(){ 
 return top == MAX-1;
 }

void push(char item) {
    if (isFull()) 
	printf("Stack Overflow!\n");
    else stack[++top] = item;
}

void pop() {
    if (!isEmpty()) 
	top--;
    else 
	printf("Stack Underflow!\n");
}

char peek() {
    if (isEmpty()) 
	return -1;
    return stack[top];
}


int precendence(char operator){
    switch(operator){
        case '*': 
		case '/':
		 return 2;
        case '+':
		 case '-': 
		return 1;
    }
    return 0;
}

int isOperator(char ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
}

void infixToPostfix(char infix[], char post[]){
    int j=0, i,len = strlen(infix);
    
    for(i=0;i<len;i++){
        if(infix[i]=='(') {
            push(infix[i]);
        }
        
        else if(infix[i]==')') {
            while (!isEmpty() && peek()!='(') {
                post[j++] = peek();
                pop();
            }
            pop(); 
        }
        
        else if(isOperator(infix[i])) {
            while (!isEmpty() && peek()!='(' && precendence(peek()) >= precendence(infix[i])) {
                post[j++] = peek();
                pop();
            }
            push(infix[i]);
        }
        
        else 
            post[j++] = infix[i];
        
    }

    
    while (!isEmpty()) {
        post[j++] = peek();
        pop();
    }
    post[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}

