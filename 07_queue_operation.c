// Program to show the array implementation of linear queue along with its
// different operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int front, rear;
    int queue[MAX];
} Queue;

void enqueue(Queue *q) {
    int item;
    if (q->rear == MAX - 1) {
        printf("Queue is Full!\n");
        return;
    }

    if (q->front == -1)  // first insertion
        q->front = 0;

    q->rear++;
    printf("Enter element: ");
    scanf("%d", &item);
    q->queue[q->rear] = item;
    printf("Element inserted successfully!\n");
}

void dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Deleted element: %d\n", q->queue[q->front]);
    q->front++;

    // reset queue when last element is deleted
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

void display(Queue *q) {
    int i;
    if (q->front == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Elements in Queue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    system("clear");
    Queue q;
    q.front = -1;
    q.rear = -1;

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
