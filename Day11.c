#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value)
{
    int i = size;

    heap[size++] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void heapify(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int extractMin()
{
    if (size <= 0)
        return -1;

    if (size == 1)
        return heap[--size];

    int root = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapify(0);

    return root;
}

void display()
{
    printf("Heap Elements: ");

    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    insert(40);
    insert(10);
    insert(30);
    insert(5);
    insert(20);

    display();

    printf("Extracted Min: %d\n", extractMin());

    display();

    return 0;
}
