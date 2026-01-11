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
//    Function Name :    DisplayDivByThree
//    Input :            Address of first node
//    Output :           Integer
//    Description :      Use to display element divisible by three
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void DisplayDivByThree(PNODE first)
{
    printf("Element divisible by three : ");
    int iNo = 0;
    while(first != NULL)
    {
        iNo = first->Data;
        if((iNo % 3) == 0)
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

    InsertFirst(&head,16);
    InsertFirst(&head,70);
    InsertFirst(&head,24);
    InsertFirst(&head,12);
    InsertFirst(&head,32);
    InsertFirst(&head,2);
    InsertFirst(&head,18);

    DisplayDivByThree(head);

    return 0;
}


