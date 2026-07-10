#include <stdio.h>

#define MAX 100

int arr[MAX];
int tree[4 * MAX];

void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int start, int end, int idx, int value)
{
    if(start == end)
    {
        arr[idx] = value;
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    if(idx <= mid)
        update(2 * node, start, mid, idx, value);
    else
        update(2 * node + 1, mid + 1, end, idx, value);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right)
{
    if(right < start || end < left)
        return 0;

    if(left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return query(2 * node, start, mid, left, right)
         + query(2 * node + 1, mid + 1, end, left, right);
}

int main()
{
    int n;

    printf("Enter Number of Days : ");
    scanf("%d", &n);

    printf("Enter Daily Sales:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    build(1, 0, n - 1);

    int choice;

    while(1)
    {
        printf("\n===== SALES ANALYTICS =====\n");
        printf("1. Range Sales Query\n");
        printf("2. Update Sales\n");
        printf("3. Exit\n");

        printf("Choice : ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int l, r;

            printf("Enter Start Day and End Day : ");
            scanf("%d%d", &l, &r);

            printf("Total Sales = %d\n",
                   query(1, 0, n - 1, l, r));
        }
        else if(choice == 2)
        {
            int day, value;

            printf("Enter Day Index : ");
            scanf("%d", &day);

            printf("New Sales : ");
            scanf("%d", &value);

            update(1, 0, n - 1, day, value);

            printf("Sales Updated.\n");
        }
        else
        {
            break;
        }
    }

    return 0;
}
