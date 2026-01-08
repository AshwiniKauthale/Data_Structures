#include<stdio.h>
#include<stdlib.h>
struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    InsertFirst
//    Input :            Data of node and Address of first node
//    Output :           Nothing
//    Description :      Use to insert node at first position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             05/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//
//    Function Name :    ReplaceNegative
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to replace negative element to 0
//    Author :           Ashwini Vishnu Kauthale
//    Data :             05/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void ReplaceNegative(PNODE first)
{
    while(first != NULL)
    {
        if(first->Data < 0)
        {
            printf("%d ",0);
        }
        else
        {
            printf("%d ",first->Data);
        }
        first = first->next;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////


int main()
{
    PNODE head = NULL;

    InsertFirst(&head,-11);
    InsertFirst(&head,30);
    InsertFirst(&head,-51);
    InsertFirst(&head,11);
    InsertFirst(&head,-37);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    ReplaceNegative(head);

    return 0;
}


