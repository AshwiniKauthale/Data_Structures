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
//    Function Name :    DisplayGreaterThanAvg
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to find out elements greater then average value of nodes
//    Author :           Ashwini Vishnu Kauthale
//    Data :             07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void DisplayGreaterThanAvg(PNODE first)
{
    int iAvg = 0;
    int iSum = 0;
    int iCount = 0;
    int iNo = 0;
    PNODE temp = first;
    while(temp != NULL)
    {
        iNo = temp->Data;
        iSum = iSum + temp->Data;
        iCount++;
        temp = temp->next;
    }

    iAvg = iSum / iCount;

    while(first != NULL)
    {
        iNo = first->Data;
        if(iNo > iAvg)
        {
            printf("%d ",iNo);
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

    InsertFirst(&head,16);
    InsertFirst(&head,17);
    InsertFirst(&head,24);
    InsertFirst(&head,35);
    InsertFirst(&head,32);
    InsertFirst(&head,25);
    InsertFirst(&head,18);

    DisplayGreaterThanAvg(head);

    return 0;
}


