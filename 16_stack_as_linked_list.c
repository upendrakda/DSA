// Program to show the implementation of stack as linked list with its different operations.
#include <stdio.h>
#include <stdlib.h>

/* Structure of a stack node */
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL; // top of the stack

/* Push operation: insert element at the top */
void push(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed to stack.\n", value);
}

/* Pop operation: remove element from the top */
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    struct Node *temp = top;
    printf("Element %d popped from stack.\n", temp->data);
    top = top->next;
    free(temp);
}

/* Display stack elements */
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
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
        printf("\n--- Stack Operations (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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
