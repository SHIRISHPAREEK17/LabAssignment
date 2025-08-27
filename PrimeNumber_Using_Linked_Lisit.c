//function like:-> Count(),Traverse(),Max(),Min(),Average()

#include <stdio.h>
#include <stdlib.h>  
#include <math.h>
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
int checkPrimeNumber(int num){
	int primeNumber=1;
	int i=2;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0){
			primeNumber=0;
			break;
		}
	}
	return primeNumber;
}
void primeNumber(struct node *head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    while (head != NULL) {
        if(checkPrimeNumber(head->val)) 
          printf("It is %d prime number \n",head->val);
        else   
         printf("It is not a %d prime number \n",head->val);
        head = head->add;
    }
    
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
        printf("5. Prime Number\n");
       
        printf("6. Exit\n");
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
			   	primeNumber(head);
                break;  
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

