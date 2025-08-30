#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is FULL\n");
        return;
    }
    if (front == -1) {   // first element
        front = rear = 0;
    } else if (rear == MAX - 1) { 
	       
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = item;
    printf("%d enqueued\n", item);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else if (front == MAX - 1) {
       
        front = 0;
    } else {
        front++;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        if (i == MAX - 1)
            i = 0;
        else
            i++;
    }
    printf("%d\n", queue[rear]); // print last element
}

int main() {
    int choice, item;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek (Front element)\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

