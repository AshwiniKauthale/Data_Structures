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
//    Function Name :    CountOdd
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to count odd numbers from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             05/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int CountOdd(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        if((first->Data % 2) != 0)
        {
            iCount++;
        }
        first = first->next;
    }
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,70);
    InsertFirst(&head,30);
    InsertFirst(&head,51);
    InsertFirst(&head,40);
    InsertFirst(&head,37);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    iRet = CountOdd(head);

    printf("Total odd numbers are : %d",iRet);

    return 0;
}


