#include<stdio.h>
#include<stdbool.h>
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
//    Function Name :    CheckSorted
//    Input :            Address of first node
//    Output :           Boolean
//    Description :      Use to check linked list is sorted or not
//    Author :           Ashwini Vishnu Kauthale
//    Data :             07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

bool CheckSorted(PNODE first)
{
    int ifirst = first->Data;
    int iNo = 0;
    while(first != NULL)
    {
        iNo = first->Data;
        if(iNo >= ifirst)
        {
            ifirst = iNo;
        }
        else
        {
            return false;
        }
        first = first->next;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    bool bRet = false;

    InsertFirst(&head,162);
    InsertFirst(&head,70);
    InsertFirst(&head,40);
    InsertFirst(&head,35);
    InsertFirst(&head,32);
    InsertFirst(&head,2);
    InsertFirst(&head,18);

    bRet = CheckSorted(head);

    if(bRet == true)
    {
        printf("Linked list is sorted\n");
    }
    else
    {
        printf("Linked list is not sorted\n");
    }

    return 0;
}


