#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

int search(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return -1;
}

void display()
{
    printf("Hash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("[%d] -> %d\n", i, hashTable[i]);
    }
}

int main()
{
    initialize();

    insert(25);
    insert(35);
    insert(45);
    insert(20);
    insert(30);

    display();

    int key = 45;

    int result = search(key);

    if (result != -1)
        printf("\n%d found at index %d\n", key, result);
    else
        printf("\n%d not found\n", key);

    return 0;
}
