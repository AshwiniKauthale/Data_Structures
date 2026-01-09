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
//    Function Name :    InsertAtPos
//    Input :            Data of node and position of node
//    Output :           Nothing
//    Description :      Use to insert node at given position
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
//    Function Name :    DisplayEvenPosition
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to display element at even position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void DisplayEvenPosition(PNODE first)
{
    int iPos = 1;
    printf("Elements at even positions are : ");

    while(first != NULL)
    {
        if((iPos % 2) == 0)
        {
            printf("%d ",first->Data);
        }
        first = first->next;
        iPos++;
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

    DisplayEvenPosition(head);

    return 0;
}


