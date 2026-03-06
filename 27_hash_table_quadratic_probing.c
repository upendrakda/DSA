// Program to implement Hash Table with Quadratic Probing
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

/* Function to initialize hash table */
void initHashTable(int hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;   // -1 indicates empty slot
}

/* Hash function */
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/* Function to insert key using Quadratic Probing */
void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    int i = 0;
    int newIndex;

    // Quadratic probing in case of collision
    while (i < TABLE_SIZE) {
        newIndex = (index + i * i) % TABLE_SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
        i++;
    }

    printf("Hash Table is Full! Cannot insert %d\n", key);
}

/* Function to display the hash table */
void display(int hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : Empty\n", i);
    }
}

int main() {
    system("clear");
    int hashTable[TABLE_SIZE];
    int n, key;

    initHashTable(hashTable);

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    printf("\nHash Table:\n");
    display(hashTable);

    return 0;
}
