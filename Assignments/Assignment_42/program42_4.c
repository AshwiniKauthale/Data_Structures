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
//    Function Name :    Maximum
//    Input :            Address of first node
//    Output :           Return maximum element
//    Description :      Use to find out the largest element from Linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             04/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int Maximum(PNODE first)
{
    int iMax = first->Data;
    while(first != NULL)
    {
        if(iMax < first->Data)
        {
            iMax = first->Data;
        }
        first = first->next;
    }
    return iMax;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,240);
    InsertFirst(&head,320);
    InsertFirst(&head,230);
    InsertFirst(&head,110);

    iRet = Maximum(head);

    printf("Largest elements is : %d",iRet);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Input  Linked List : | 110 |->| 230 |->| 320 |->| 240 |
//           Output             :  320
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
