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
//    Data :             07/01/2026
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
//    Function Name :    DisplayAlternate
//    Input :            Address of first node
//    Output :           Display Alternate node
//    Description :      Use to Display alternate nodes
//    Author :           Ashwini Vishnu Kauthale
//    Data :             07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void DisplayAlternate(PNODE first)
{
    while(first != NULL)
    {
        printf("%d   __  ",first->Data);
        first = first->next->next; 
    }
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,70);
    InsertFirst(&head,40);
    InsertFirst(&head,35);
    InsertFirst(&head,32);
    InsertFirst(&head,2);
    InsertFirst(&head,18);

    DisplayAlternate(head);

    return 0;
}


