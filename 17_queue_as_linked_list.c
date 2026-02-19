// Program to show the implemntation of queue as linked list with its different operations
#include <stdio.h>
#include <stdlib.h>

/* Structure of a queue node */
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL; // front of the queue
struct Node *rear = NULL;  // rear of the queue

/* Enqueue operation: insert element at the rear */
void enqueue(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow! Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Element %d enqueued to queue.\n", value);
}

/* Dequeue operation: remove element from the front */
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Element %d dequeued from queue.\n", temp->data);
    front = front->next;

    if (front == NULL) // if queue becomes empty
        rear = NULL;

    free(temp);
}

/* Display queue elements */
void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    system("clear");
    int choice, value;

    do {
        printf("\n--- Queue Operations (Linked List) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
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
