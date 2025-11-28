//Queue implements using static array
#include<stdio.h>
#define MAX 10
int queue[MAX];
int front=-1;
int rear=-1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int item){
	
	if (isFull()) 
        printf("Queue is full!.\n");
    
	else {
        if (front == -1) 
            front = 0;
        queue[++rear] = item;
        printf("Enqueued: %d\n", item);
    }
	
}

void dequeue(){
	 if (isEmpty()) 
        printf("Queue is empty!\n");
     if(front==rear)
        front=rear=-1;
     else 
        printf("Dequeued: %d\n", queue[front++]);
    
}
void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
    	int i;
        printf("Queue elements: ");
        for ( i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main(){
	int choice, item;
    do {
        printf("1. Enqueue\n"
       "2. Dequeue\n"
       "3. Peek (Front element)\n"
       "4. Display\n"
       "5. Exit\n"
       "Enter your choice: ");
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
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
