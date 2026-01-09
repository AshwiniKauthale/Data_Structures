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
//    Data :             06/01/2026
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
//    Function Name :    ReplaceOdd
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to replace Odd numbers to 1
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void ReplaceOdd(PNODE first)
{
    while(first != NULL)
    {
        if((first->Data % 2) != 0)
        {
            printf("%d ",1);
            first = first->next;
        }
        else
        {
            printf("%d ",first->Data);
            first = first->next;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,15);
    InsertFirst(&head,30);
    InsertFirst(&head,23);
    InsertFirst(&head,11);
    InsertFirst(&head,37);
    InsertFirst(&head,7);
    InsertFirst(&head,18);

    ReplaceOdd(head);

    return 0;
}
