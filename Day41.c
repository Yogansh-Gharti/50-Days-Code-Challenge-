#include <stdio.h>

#define MAX 100

typedef struct
{
    int price;
} Order;

Order buyHeap[MAX], sellHeap[MAX];
int buySize = 0, sellSize = 0;

void swap(Order *a, Order *b)
{
    Order temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- BUY MAX HEAP ---------- */

void insertBuy(int price)
{
    buyHeap[buySize].price = price;
    int i = buySize++;

    while(i > 0)
    {
        int p = (i - 1) / 2;

        if(buyHeap[p].price >= buyHeap[i].price)
            break;

        swap(&buyHeap[p], &buyHeap[i]);
        i = p;
    }
}

void heapifyBuy(int i)
{
    while(1)
    {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if(l < buySize &&
           buyHeap[l].price > buyHeap[largest].price)
            largest = l;

        if(r < buySize &&
           buyHeap[r].price > buyHeap[largest].price)
            largest = r;

        if(largest == i)
            break;

        swap(&buyHeap[i], &buyHeap[largest]);
        i = largest;
    }
}

/* ---------- SELL MIN HEAP ---------- */

void insertSell(int price)
{
    sellHeap[sellSize].price = price;
    int i = sellSize++;

    while(i > 0)
    {
        int p = (i - 1) / 2;

        if(sellHeap[p].price <= sellHeap[i].price)
            break;

        swap(&sellHeap[p], &sellHeap[i]);
        i = p;
    }
}

void heapifySell(int i)
{
    while(1)
    {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if(l < sellSize &&
           sellHeap[l].price < sellHeap[smallest].price)
            smallest = l;

        if(r < sellSize &&
           sellHeap[r].price < sellHeap[smallest].price)
            smallest = r;

        if(smallest == i)
            break;

        swap(&sellHeap[i], &sellHeap[smallest]);
        i = smallest;
    }
}

/* ---------- MATCH ENGINE ---------- */

void matchOrders()
{
    if(buySize == 0 || sellSize == 0)
    {
        printf("\nNo Orders Available.\n");
        return;
    }

    if(buyHeap[0].price >= sellHeap[0].price)
    {
        printf("\nTrade Executed!\n");
        printf("Buy Price  : %d\n", buyHeap[0].price);
        printf("Sell Price : %d\n", sellHeap[0].price);

        buyHeap[0] = buyHeap[--buySize];
        heapifyBuy(0);

        sellHeap[0] = sellHeap[--sellSize];
        heapifySell(0);
    }
    else
    {
        printf("\nNo Matching Orders.\n");
    }
}

void display()
{
    int i;

    printf("\nBuy Orders (Max Heap)\n");
    for(i = 0; i < buySize; i++)
        printf("%d ", buyHeap[i].price);

    printf("\n\nSell Orders (Min Heap)\n");
    for(i = 0; i < sellSize; i++)
        printf("%d ", sellHeap[i].price);

    printf("\n");
}

int main()
{
    int choice, price;

    while(1)
    {
        printf("\n===== STOCK ORDER BOOK =====\n");
        printf("1. Add Buy Order\n");
        printf("2. Add Sell Order\n");
        printf("3. Match Orders\n");
        printf("4. Display Orders\n");
        printf("5. Exit\n");

        printf("Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Buy Price : ");
                scanf("%d", &price);
                insertBuy(price);
                break;

            case 2:
                printf("Sell Price : ");
                scanf("%d", &price);
                insertSell(price);
                break;

            case 3:
                matchOrders();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}
