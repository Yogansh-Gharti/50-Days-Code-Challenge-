#include <stdio.h>
#include <string.h>

void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0;
    int j = 0;
    int found = 0;

    while(i < n)
    {
        if(pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            printf("Pattern Found at Index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if(!found)
        printf("Pattern Not Found\n");
}

int main()
{
    char text[500];
    char pattern[100];

    printf("Enter DNA Sequence : ");
    scanf("%s", text);

    printf("Enter Pattern : ");
    scanf("%s", pattern);

    KMPSearch(text, pattern);

    return 0;
}
