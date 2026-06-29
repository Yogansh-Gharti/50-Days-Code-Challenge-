#include <stdio.h>
#include <string.h>

#define MAX 100

struct Vehicle
{
    char number[20];
    char owner[50];
    int arrival;
};

struct Vehicle heap[MAX];
int size = 0;

void swap(struct Vehicle *a, struct Vehicle *b)
{
    struct Vehicle temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent].arrival <= heap[index].arrival)
            break;

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

void heapifyDown(int index)
{
    while(1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < size && heap[left].arrival < heap[smallest].arrival)
            smallest = left;

        if(right < size && heap[right].arrival < heap[smallest].arrival)
            smallest = right;

        if(smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);

        index = smallest;
    }
}

void parkVehicle()
{
    if(size == MAX)
    {
        printf("\nParking Full!\n");
        return;
    }

    printf("\nVehicle Number : ");
    scanf("%s", heap[size].number);

    printf("Owner Name : ");
    scanf(" %[^\n]", heap[size].owner);

    printf("Arrival Time (minutes): ");
    scanf("%d", &heap[size].arrival);

    heapifyUp(size);

    size++;

    printf("\nVehicle Parked Successfully.\n");
}

void removeVehicle()
{
    if(size == 0)
    {
        printf("\nParking Empty.\n");
        return;
    }

    printf("\nVehicle Leaving\n");
    printf("-----------------------\n");
    printf("Vehicle : %s\n", heap[0].number);
    printf("Owner   : %s\n", heap[0].owner);
    printf("Arrival : %d\n", heap[0].arrival);

    heap[0] = heap[size - 1];

    size--;

    heapifyDown(0);
}

void display()
{
    if(size == 0)
    {
        printf("\nParking Empty.\n");
        return;
    }

    printf("\nCurrent Parking Queue\n");

    for(int i = 0; i < size; i++)
    {
        printf("\nVehicle %d\n", i + 1);
        printf("Number : %s\n", heap[i].number);
        printf("Owner  : %s\n", heap[i].owner);
        printf("Arrival: %d\n", heap[i].arrival);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n====== SMART PARKING ======\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Earliest Vehicle\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("\nChoice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                parkVehicle();
                break;

            case 2:
                removeVehicle();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
