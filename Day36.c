#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char text[100];
    struct Node *next;
}Node;

Node *undoStack=NULL;
Node *redoStack=NULL;

void push(Node **top,char str[])
{
    Node *temp=(Node*)malloc(sizeof(Node));

    strcpy(temp->text,str);

    temp->next=*top;

    *top=temp;
}

char* pop(Node **top)
{
    if(*top==NULL)
        return NULL;

    Node *temp=*top;

    *top=temp->next;

    char *str=(char*)malloc(100);

    strcpy(str,temp->text);

    free(temp);

    return str;
}

void clearRedo()
{
    while(redoStack)
    {
        free(pop(&redoStack));
    }
}

void addText()
{
    char str[100];

    printf("Enter Text : ");
    scanf(" %[^\n]",str);

    push(&undoStack,str);

    clearRedo();
}

void undo()
{
    char *str=pop(&undoStack);

    if(str==NULL)
    {
        printf("Nothing to Undo\n");
        return;
    }

    push(&redoStack,str);

    free(str);
}

void redo()
{
    char *str=pop(&redoStack);

    if(str==NULL)
    {
        printf("Nothing to Redo\n");
        return;
    }

    push(&undoStack,str);

    free(str);
}

void current()
{
    if(undoStack==NULL)
    {
        printf("Editor Empty\n");
        return;
    }

    printf("\nCurrent Text : %s\n",undoStack->text);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Add Text\n");
        printf("2.Undo\n");
        printf("3.Redo\n");
        printf("4.Current Text\n");
        printf("5.Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addText(); break;
            case 2: undo(); break;
            case 3: redo(); break;
            case 4: current(); break;
            case 5: return 0;
        }
    }
}
