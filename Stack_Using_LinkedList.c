#include <stdio.h>
#include <stdlib.h>  
struct node {
    int val;
    struct node *add;
};

// Function to insert (push) an element into stack
struct node *push(struct node *head, int item) {
    struct node *temp;
    
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        head->val = item;
        head->add = NULL;
    } 
	else {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = item;
        temp->add = head;
        head = temp;
    }
    return head;
}

// Function to display stack elements
void display(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    
    printf("Stack elements: ");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->add;
    }
    printf("\n");
}

struct node *pop(struct node *head) {
    struct node *temp;
    if (head == NULL) {
        printf("Stack is empty..\n");
        return head;  
    } else {
        temp = head;
        printf("Popped: %d\n", head->val);
        head = head->add;
        free(temp);
    }
    return head;
}

int main() {
    struct node *head = NULL;
    int choice, item;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &item);
                head = push(head, item);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

