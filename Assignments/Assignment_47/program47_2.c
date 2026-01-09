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
//    Function Name :    CountDigits
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to count digits of each node
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void CountDigits(PNODE first)
{
    int iDigit = 0;
    int iNo = 0;
    int iCount = 0;

    while(first != NULL)
    {
        iCount = 0;
        iNo = first->Data;
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iCount++;
            iNo = iNo / 10;
        }
        printf("%d ",iCount);
        first = first->next;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,1);
    InsertFirst(&head,30);
    InsertFirst(&head,521);
    InsertFirst(&head,11);
    InsertFirst(&head,37);
    InsertFirst(&head,2067);
    InsertFirst(&head,1111);

    CountDigits(head);

    return 0;
}


