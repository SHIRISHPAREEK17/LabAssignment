#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at beginning
struct Node* insertAtFirst(struct Node *head, int item) {
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = head;
    head = temp;
    return head;
}

// Insert at end
struct Node* insertAtLast(struct Node *head, int item) {
    if(head == NULL) 
	  return insertAtFirst(head, item);

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;

    struct Node *ptr = head;
    while(ptr->next != NULL) 
	   ptr = ptr->next;
	
    ptr->next = temp;

    return head;
}

// Insert before target
struct Node* addBefore(struct Node* head, int target, int item) {
    if(head == NULL) {
        printf("Target Not found\n");
        return head;
    }

    struct Node *ptr = head, *preptr = NULL;
    while(ptr != NULL && ptr->data != target) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Target Not found\n");
        return head;
    }

    if(ptr == head) 
	return insertAtFirst(head, item);

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = ptr;
    preptr->next = temp;
    return head;
}

// Insert after target
struct Node* addAfter(struct Node* head, int target, int item) {
    if(head == NULL) {
        printf("List is Empty\n");
        return head;
    }

    struct Node *ptr = head;
    while(ptr != NULL && ptr->data != target) 
	ptr = ptr->next;

    if(ptr == NULL) {
        printf("Target Not found\n");
        return head;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

// Delete first node
struct Node* deleteAtFirst(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

// Delete last node
struct Node* deleteAtLast(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty\n");
        return head;
    }
    if(head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node *ptr = head, *preptr = NULL;
    while(ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return head;
}

// Delete target node
struct Node* deleteAtTarget(struct Node* head, int target) {
    if(head == NULL) {
        printf("List is Empty\n");
        return head;
    }

    struct Node *ptr = head, *preptr = NULL;
    while(ptr != NULL && ptr->data != target) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Target not found\n");
        return head;
    }

    if(ptr == head) return deleteAtFirst(head);

    preptr->next = ptr->next;
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return head;
}

// Display list
void display(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* ptr = head;
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
struct Node* reverseList(struct Node *head){
	if(head==NULL){
		printf("List is Empty..");
		return head;
	}
	struct Node *ptr1=NULL,*ptr2=head,*ptr3=head->next;
	while(ptr3!=NULL){
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
		ptr3=ptr3->next;
	}
	ptr2->next=ptr1;
	head=ptr2;
	return head;
}
int middleNode(struct Node* head) {
    if (head == NULL) {
        return -1;
    }
    struct Node *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

// Main function with menu
int main() {
    struct Node* head = NULL;
    int choice, value, target;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert Before Target\n");
        printf("4. Insert After Target\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Delete Target Node\n");
        printf("8. Display List\n");
        printf("9. Reverse List\n");
        printf("10.Middle Node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtFirst(head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtLast(head, value);
                break;
            case 3:
                printf("Enter target: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = addBefore(head, target, value);
                break;
            case 4:
                printf("Enter target: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = addAfter(head, target, value);
                break;
            case 5:
                head = deleteAtFirst(head);
                break;
            case 6:
                head = deleteAtLast(head);
                break;
            case 7:
                printf("Enter target to delete: ");
                scanf("%d", &target);
                head = deleteAtTarget(head, target);
                break;
            case 8:
                display(head);
                break;
            case 9:
			   head=reverseList(head);
			   break;  
			case 10:
			    if(middleNode(head)!=-1) 
			       printf("Middle Node is : %d",middleNode(head));   
			    else
			        printf("List is empty..");
			    break;    
			        
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}

