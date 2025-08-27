//function like:-> Count(),Traverse(),Max(),Min(),Average()

#include <stdio.h>
#include <stdlib.h>  
struct node {
    int val;
    struct node *add;
};

// Function to insert (push) an element into stack
struct node *insert(struct node *head, int item) {
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

struct node *delete(struct node *head) {
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
int count(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return 0;
    }

    int count =0;
    while (head != NULL) {
        count++;
        head = head->add;
    }
    return count;
} 
int sum(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return 0;
    }

    int sum=0;
    while (head != NULL) {
        sum+=head->val;
        head = head->add;
    }
    return sum;
} 
int max(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return 0;
    }

    int max=head->val;
    while (head != NULL) {
        if(head->val>max)
        	max=head->val;
		
        head = head->add;
    }
    return max;
} 
int min(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return 0;
    }

    int min=head->val;
    while (head != NULL) {
        if(head->val<min)
        	min=head->val;
		
        head = head->add;
    }
    return min;
} 
int main() {
    struct node *head = NULL;
    int choice, item;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Sum\n");
        printf("6. Max\n");
        printf("7. Min\n");
        printf("8. Average\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &item);
                head = insert(head, item);
                break;
            case 2:
                head = delete(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Size of List: %d",count(head));
                break;
			case 5:
                printf("Sum of List: %d",sum(head));
                break; 
			case 6:
                printf("Max from List: %d",max(head));
                break; 
			case 7:
                printf("Min from List: %d",min(head));
                break; 
			case 8:
                if (head == NULL) 
                   printf("Stack is empty, cannot calculate average\n");
               else {
                float avg = (float)sum(head) / count(head);
                printf("Average from List: %.2f\n", avg);
                }
               break;			    
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);

    return 0;
}

