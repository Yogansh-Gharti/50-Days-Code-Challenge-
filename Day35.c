#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET];
    int isEnd;
}TrieNode;

TrieNode* createNode()
{
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));

    node->isEnd = 0;

    for(int i=0;i<ALPHABET;i++)
        node->children[i]=NULL;

    return node;
}

void insert(TrieNode *root,char word[])
{
    TrieNode *curr=root;

    for(int i=0;word[i];i++)
    {
        int index=word[i]-'a';

        if(curr->children[index]==NULL)
            curr->children[index]=createNode();

        curr=curr->children[index];
    }

    curr->isEnd=1;
}

void printWords(TrieNode *root,char word[],int level)
{
    if(root->isEnd)
    {
        word[level]='\0';
        printf("%s\n",word);
    }

    for(int i=0;i<26;i++)
    {
        if(root->children[i])
        {
            word[level]=i+'a';
            printWords(root->children[i],word,level+1);
        }
    }
}

void searchPrefix(TrieNode *root,char prefix[])
{
    TrieNode *curr=root;

    for(int i=0;prefix[i];i++)
    {
        int index=prefix[i]-'a';

        if(curr->children[index]==NULL)
        {
            printf("No Suggestions Found.\n");
            return;
        }

        curr=curr->children[index];
    }

    char result[100];

    strcpy(result,prefix);

    printWords(curr,result,strlen(prefix));
}

int main()
{
    TrieNode *root=createNode();

    int n;

    printf("Number of Words : ");
    scanf("%d",&n);

    char word[100];

    printf("\nEnter Dictionary Words\n");

    for(int i=0;i<n;i++)
    {
        scanf("%s",word);
        insert(root,word);
    }

    printf("\nEnter Prefix : ");
    scanf("%s",word);

    printf("\nSuggestions\n\n");

    searchPrefix(root,word);

    return 0;
}
