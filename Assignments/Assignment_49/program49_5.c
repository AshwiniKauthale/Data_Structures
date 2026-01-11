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
//    Function Name :    CountTwoDigit
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to Count two digits nodes from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int CountTwoDigit(PNODE first)
{
    int iCount = 0;
    int iCountTwo = 0;
    int iNo = 0;
    int iDigit = 0;
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

        if(iCount == 2)
        {
            iCountTwo++;
        }
        first = first->next;
    }
    return iCountTwo;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,16);
    InsertFirst(&head,70);
    InsertFirst(&head,24);
    InsertFirst(&head,155);
    InsertFirst(&head,329);
    InsertFirst(&head,200);
    InsertFirst(&head,18);

    iRet = CountTwoDigit(head);
    printf("Two digit number is : %d",iRet);

    return 0;
}


