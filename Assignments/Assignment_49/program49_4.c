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
//    Function Name :    CountDivByFive
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to Count element divisible by Five
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int CountDivByFive(PNODE first)
{
    int iCount = 0;
    int iNo = 0;
    while(first != NULL)
    {
        iNo = first->Data;
        if((iNo % 5) == 0)
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

    InsertFirst(&head,16);
    InsertFirst(&head,70);
    InsertFirst(&head,24);
    InsertFirst(&head,15);
    InsertFirst(&head,32);
    InsertFirst(&head,20);
    InsertFirst(&head,18);

    iRet = CountDivByFive(head);
    printf("Number of element divisible by five is : %d",iRet);

    return 0;
}


