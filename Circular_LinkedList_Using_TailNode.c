#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node *next;
};

// Insert node at the beginning (O(1) using tail pointer)
struct Node* insertionAtFirst(struct Node *tail, int item) {
    struct Node *temp;
    // If list is empty, create first node (points to itself)
    if (tail == NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = item;
        temp->next = temp;   // circular link
        tail = temp;
        return tail;
    }
    // Otherwise, insert new node after tail, but before head
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = tail->next;  // new node points to current head
    tail->next = temp;        // tail points to new head
    return tail;              // tail stays the same
}

// Insert node at the end (O(1) using tail pointer)
struct Node* insertionAtLast(struct Node *tail, int item) {
    // If list is empty, simply call insertionAtFirst
    if (tail == NULL) {
        return insertionAtFirst(tail, item);
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = tail->next;  // new node points to head
    tail->next = temp;        // old tail points to new node
    tail = temp;              // update tail to new node
    return tail;
}

// Delete node by value
struct Node* deleteNode(struct Node *tail, int target) {
    if (tail == NULL) {   // empty list
        printf("List is Empty..\n");
        return tail;
    }

    struct Node *ptr = tail->next;   // start from head
    struct Node *preptr = tail;      // previous pointer

    int flag = 0;
    // Traverse the list to find target node
    do {
        if (ptr->data == target) {
            flag = 1; // target found
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    } while (ptr != tail->next);

    if (flag == 0) {  // target not found
        printf("Number not found..\n");
        return tail;
    }

    // Case 1: deleting the only node
    if (ptr == tail && tail->next == tail) {
        free(ptr);
        return NULL;  // list becomes empty
    }

    // Case 2: deleting tail node
    if (ptr == tail) {
        preptr->next = ptr->next; // bypass node
        tail = preptr;            // update tail
    }
    // Case 3: deleting head or middle node
    else {
        preptr->next = ptr->next; // bypass node
    }

    free(ptr); // free memory
    printf("Deleted %d\n", target);
    return tail;
}

// Display circular linked list
void display(struct Node *tail) {
    if (tail == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node *ptr = tail->next;  // start from head
    printf("List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next); // stop when back at head
    printf("\n");
}


// Main function
int main() {
    struct Node *tail = NULL;

    // Insert elements
    tail = insertionAtFirst(tail, 10);
    
    tail = insertionAtLast(tail, 20);
    tail = insertionAtLast(tail, 30);
    tail = insertionAtLast(tail, 40);
    tail = insertionAtLast(tail, 50);
    tail = insertionAtLast(tail, 60);
    tail = insertionAtFirst(tail, 5);

    display(tail);  // show list
   
    // Delete one node
    tail = deleteNode(tail, 40);

    display(tail);  // show list after deletion
    
    return 0;
}

