//Queue using Linked-List
#include <stdio.h>
#include <stdlib.h>  
struct node {
    int val;
    struct node *add;
};
struct node *enqueue(struct node *head, int item) {  
    if (head == NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        head->val = item;
        head->add = NULL;
    } 
	else {
		struct node *temp,*ptr=head;
        temp = (struct node *) malloc(sizeof(struct node));
        temp->val = item;
        temp->add = NULL;
        while(ptr->add!=NULL){
        	ptr=ptr->add;
		}
		ptr->add=temp;
    }
       return head;
}
// Function to display stack elements
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    
    printf("Elements: ");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->add;
    }
    printf("\n");
}

struct node *dequeue(struct node *head) {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty..\n");
        return head;  
    } else {
        temp = head;
        printf("Deleted: %d\n", head->val);
        head = head->add;
        free(temp);
    }
    return head;
}

int main() {
    struct node *head = NULL;
    int choice, item;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                head = enqueue(head, item);
                break;
            case 2:
                head = dequeue(head);
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

