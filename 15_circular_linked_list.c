// Program to show the implementation of circulat linked list along with its different operations.
// (Operations: Node creation, node insertion, and Node deletion at the beginning, end and specified position)
#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create a new node */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at beginning */
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted at end.\n");
}

/* Insert at specific position */
void insertAtPosition(int value, int pos) {
    int i;
    struct Node *temp = head;

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && i < pos - 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

/* Delete from beginning */
void deleteAtBeginning() {
    struct Node *temp = head;
    struct Node *last;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {   // only one node
        free(head);
        head = NULL;
    } else {
        last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Node deleted from beginning.\n");
}

/* Delete from end */
void deleteAtEnd() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {   // only one node
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
    printf("Node deleted from end.\n");
}

/* Delete from specific position */
void deleteAtPosition(int pos) {
    int i;
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i < pos) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", pos);
}

/* Display the circular linked list */
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    system("clear");
    int choice, value, pos;

    do {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
