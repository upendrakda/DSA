// Program to show the array implementation of circular queue along with its 
// different operation
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int front, rear;
    int queue[MAX];
} CQueue;

/* Enqueue operation */
void enqueue(CQueue *q) {
    int item;

    // Check for overflow
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is Full!\n");
        return;
    }

    if (q->front == -1) {   // first insertion
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    printf("Enter element: ");
    scanf("%d", &item);
    q->queue[q->rear] = item;
    printf("Element inserted successfully!\n");
}

/* Dequeue operation */
void dequeue(CQueue *q) {
    if (q->front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Deleted element: %d\n", q->queue[q->front]);

    // If only one element was present
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

/* Display operation */
void display(CQueue *q) {
    int i;

    if (q->front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Elements in Circular Queue: ");
    i = q->front;
    while (1) {
        printf("%d ", q->queue[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CQueue q;
    q.front = -1;
    q.rear = -1;

    system("clear");
    
    int choice;

    do {
        printf("\n--- Select Options ---\n");
        printf("1. enqueue()\n");
        printf("2. dequeue()\n");
        printf("3. display()\n");
        printf("4. exit()\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
