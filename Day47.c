#include <stdio.h>

#define INF 100000

int main()
{
    int n;

    printf("Enter Number of Coin Types: ");
    scanf("%d", &n);

    int coin[n];

    printf("Enter Coin Values:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    int amount;

    printf("Enter Target Amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];

    dp[0] = 0;

    for(int i = 1; i <= amount; i++)
        dp[i] = INF;

    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coin[j] <= i)
            {
                if(dp[i - coin[j]] + 1 < dp[i])
                    dp[i] = dp[i - coin[j]] + 1;
            }
        }
    }

    if(dp[amount] == INF)
        printf("\nNot Possible\n");
    else
        printf("\nMinimum Coins Required = %d\n", dp[amount]);

    return 0;
}
