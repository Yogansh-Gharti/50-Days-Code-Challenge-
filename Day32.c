#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    char data;
    int freq;

    struct Node *left;
    struct Node *right;
};

struct Node* heap[MAX];
int size = 0;

struct Node* createNode(char data, int freq)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent]->freq <= heap[index]->freq)
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

        if(left < size && heap[left]->freq < heap[smallest]->freq)
            smallest = left;

        if(right < size && heap[right]->freq < heap[smallest]->freq)
            smallest = right;

        if(smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void insertHeap(struct Node *node)
{
    heap[size] = node;
    heapifyUp(size);
    size++;
}

struct Node* extractMin()
{
    struct Node *temp = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return temp;
}

void printCodes(struct Node *root, int code[], int top)
{
    if(root->left)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if(root->right)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if(root->left == NULL && root->right == NULL)
    {
        printf("%c : ", root->data);

        for(int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter Number of Characters : ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        printf("\nCharacter : ");
        scanf(" %c", &ch);

        printf("Frequency : ");
        scanf("%d", &freq);

        insertHeap(createNode(ch, freq));
    }

    while(size > 1)
    {
        struct Node *left = extractMin();
        struct Node *right = extractMin();

        struct Node *newNode = createNode('$',
                        left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        insertHeap(newNode);
    }

    int code[100];

    printf("\nHuffman Codes\n\n");

    printCodes(heap[0], code, 0);

    return 0;
}
