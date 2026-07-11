#include <stdio.h>

#define MAX 100

int BIT[MAX];
int inventory[MAX];
int n;

void update(int index, int value)
{
    while(index <= n)
    {
        BIT[index] += value;
        index += index & (-index);
    }
}

int prefixSum(int index)
{
    int sum = 0;

    while(index > 0)
    {
        sum += BIT[index];
        index -= index & (-index);
    }

    return sum;
}

int rangeSum(int left, int right)
{
    return prefixSum(right) - prefixSum(left - 1);
}

int main()
{
    printf("Enter Number of Shelves : ");
    scanf("%d",&n);

    printf("Enter Product Quantity\n");

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&inventory[i]);
        update(i, inventory[i]);
    }

    int choice;

    while(1)
    {
        printf("\n===== INVENTORY SYSTEM =====\n");
        printf("1. Update Shelf Quantity\n");
        printf("2. Prefix Query (1 to X)\n");
        printf("3. Range Query\n");
        printf("4. Exit\n");

        printf("Choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            int shelf,newValue,diff;

            printf("Shelf Number : ");
            scanf("%d",&shelf);

            printf("New Quantity : ");
            scanf("%d",&newValue);

            diff = newValue - inventory[shelf];

            inventory[shelf] = newValue;

            update(shelf,diff);

            printf("Inventory Updated.\n");
        }

        else if(choice==2)
        {
            int x;

            printf("Enter Shelf Number : ");
            scanf("%d",&x);

            printf("Total Products = %d\n",
                   prefixSum(x));
        }

        else if(choice==3)
        {
            int l,r;

            printf("Enter Left and Right Shelf : ");
            scanf("%d%d",&l,&r);

            printf("Products = %d\n",
                   rangeSum(l,r));
        }

        else
            break;
    }

    return 0;
}
