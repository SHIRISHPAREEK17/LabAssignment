#include <stdio.h>
#include <string.h>
#define MAX 7

int stack[MAX];
int top1 = -1;
int top2 = MAX;

// Utility functions
int Stack1isEmpty() {
    return top1 == -1;
}
int Stack2isEmpty() {
    return top2 == MAX;
}
int isFull() {
    return top1 == top2 - 1;
}

// Push into Stack 1 
void pushIntoStack1(int item) {
    if (isFull()) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top1] = item;
        printf("%d inserted into Stack1\n", item);
    }
}

// Push into Stack 2
void pushIntoStack2(int item) {
    if (isFull()) {
        printf("Stack Overflow!\n");
    } else {
        stack[--top2] = item;
        printf("%d inserted into Stack2\n", item);
    }
}

// Pop from Stack1
void popIntoStack1() {
    if (Stack1isEmpty()) {
        printf("Stack1 Underflow!\n");
    } else {
        printf("%d popped from Stack1\n", stack[top1--]);
    }
}

// Pop from Stack2
void popIntoStack2() {
    if (Stack2isEmpty()) {
        printf("Stack2 Underflow!\n");
    } else {
        printf("%d popped from Stack2\n", stack[top2++]);
    }
}

// Peek functions
int peekStack1() {
    if (Stack1isEmpty()) {
        printf("Stack1 is Empty!\n");
        return -1;
    } else {
        return stack[top1];
    }
}
int peekStack2() {
    if (Stack2isEmpty()) {
        printf("Stack2 is Empty!\n");
        return -1;
    } else {
        return stack[top2];
    }
}

int main() {
    int choice, item;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Push into Stack 1...\n"
               "2. Push into Stack 2...\n"
               "3. Pop  from Stack 1...\n"
               "4. Pop  from Stack 2...\n"
               "5. Peek from Stack 1...\n"
               "6. Peek from Stack 2...\n"
               "7. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push into Stack 1: ");
                scanf("%d", &item);
                pushIntoStack1(item);
                break;

            case 2:
                printf("Enter item to push into Stack 2: ");
                scanf("%d", &item);
                pushIntoStack2(item);
                break;

            case 3:
                popIntoStack1();
                break;

            case 4:
                popIntoStack2();
                break;

            case 5:
                item = peekStack1();
                if (item != -1)
                    printf("Top of Stack 1: %d\n", item);
                break;

            case 6:
                item = peekStack2();
                if (item != -1)
                    printf("Top of Stack 2: %d\n", item);
                break;

            case 7:
                printf("Thank you..\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

