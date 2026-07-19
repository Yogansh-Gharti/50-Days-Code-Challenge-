#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n;

    printf("Enter Number of Items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter Weight of Each Item:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter Value of Each Item:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    int capacity;

    printf("Enter Backpack Capacity: ");
    scanf("%d", &capacity);

    int dp[n + 1][capacity + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if(weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum Value = %d\n", dp[n][capacity]);

    return 0;
}
