#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Transaction
{
    int transactionID;
    float amount;
    struct Transaction *next;
};

struct Transaction *table[SIZE];

int hashFunction(int id)
{
    return id % SIZE;
}

void addTransaction()
{
    struct Transaction *newNode;
    newNode = (struct Transaction *)malloc(sizeof(struct Transaction));

    printf("\nEnter Transaction ID : ");
    scanf("%d", &newNode->transactionID);

    printf("Enter Amount : ");
    scanf("%f", &newNode->amount);

    int index = hashFunction(newNode->transactionID);

    newNode->next = table[index];
    table[index] = newNode;

    printf("\nTransaction Added Successfully.\n");
}

void searchTransaction()
{
    int id;

    printf("\nEnter Transaction ID : ");
    scanf("%d", &id);

    int index = hashFunction(id);

    struct Transaction *temp = table[index];

    while(temp != NULL)
    {
        if(temp->transactionID == id)
        {
            printf("\nTransaction Found\n");
            printf("ID : %d\n", temp->transactionID);
            printf("Amount : %.2f\n", temp->amount);
            return;
        }

        temp = temp->next;
    }

    printf("\nTransaction Not Found.\n");
}

void deleteTransaction()
{
    int id;

    printf("\nEnter Transaction ID : ");
    scanf("%d", &id);

    int index = hashFunction(id);

    struct Transaction *temp = table[index];
    struct Transaction *prev = NULL;

    while(temp != NULL)
    {
        if(temp->transactionID == id)
        {
            if(prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("\nTransaction Deleted.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nTransaction Not Found.\n");
}

void displayTransactions()
{
    printf("\n===== HASH TABLE =====\n");

    for(int i = 0; i < SIZE; i++)
    {
        printf("\nBucket %d : ", i);

        struct Transaction *temp = table[i];

        while(temp != NULL)
        {
            printf("[ID:%d Amt:%.2f] -> ",
                   temp->transactionID,
                   temp->amount);

            temp = temp->next;
        }

        printf("NULL");
    }

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n====== BANK SYSTEM ======\n");
        printf("1. Add Transaction\n");
        printf("2. Search Transaction\n");
        printf("3. Delete Transaction\n");
        printf("4. Display Hash Table\n");
        printf("5. Exit\n");

        printf("\nChoice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addTransaction();
                break;

            case 2:
                searchTransaction();
                break;

            case 3:
                deleteTransaction();
                break;

            case 4:
                displayTransactions();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
