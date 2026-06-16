#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode *createNode()
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    node->isEndOfWord = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
            current->children[index] = createNode();

        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

int search(struct TrieNode *root, char *word)
{
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->isEndOfWord;
}

int main()
{
    struct TrieNode *root = createNode();

    insert(root, "cat");
    insert(root, "car");
    insert(root, "dog");
    insert(root, "apple");

    printf("Search cat: %s\n",
           search(root, "cat") ? "Found" : "Not Found");

    printf("Search car: %s\n",
           search(root, "car") ? "Found" : "Not Found");

    printf("Search cow: %s\n",
           search(root, "cow") ? "Found" : "Not Found");

    return 0;
}
