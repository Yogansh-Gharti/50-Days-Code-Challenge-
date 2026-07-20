#include <stdio.h>

int main()
{
    int n;

    printf("Enter Number of Days: ");
    scanf("%d", &n);

    int price[n];

    printf("Enter Stock Prices:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&price[i]);

    int minPrice=price[0];
    int minDay=0;

    int maxProfit=0;
    int buyDay=0;
    int sellDay=0;

    for(int i=1;i<n;i++)
    {
        if(price[i]<minPrice)
        {
            minPrice=price[i];
            minDay=i;
        }

        if(price[i]-minPrice>maxProfit)
        {
            maxProfit=price[i]-minPrice;
            buyDay=minDay;
            sellDay=i;
        }
    }

    if(maxProfit==0)
    {
        printf("\nNo Profit Possible\n");
    }
    else
    {
        printf("\nMaximum Profit = %d\n",maxProfit);
        printf("Buy on Day %d (Price = %d)\n",
                buyDay+1,
                price[buyDay]);

        printf("Sell on Day %d (Price = %d)\n",
                sellDay+1,
                price[sellDay]);
    }

    return 0;
}
