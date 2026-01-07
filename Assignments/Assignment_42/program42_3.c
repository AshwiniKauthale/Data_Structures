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
//    Data :             04/01/2026
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
//    Function Name :    Addition
//    Input :            Address of first node
//    Output :           return addition of all elements
//    Description :      Use to Add the values of all nodes
//    Author :           Ashwini Vishnu Kauthale
//    Data :             04/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int Addition(PNODE first)
{
    int iSum = 0;
    while(first != NULL)
    {
        iSum = iSum + (first->Data);
        first = first->next;
    }
    return iSum;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,40);
    InsertFirst(&head,30);
    InsertFirst(&head,20);
    InsertFirst(&head,10);

    iRet = Addition(head);

    printf("Addition of all elements is : %d",iRet);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Input  Linked List : | 10 |->| 20 |->| 30 |->| 40 |
//           Output             :  100
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

