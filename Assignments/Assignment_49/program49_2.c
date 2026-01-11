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
//    Function Name :    CheckAllPositive
//    Input :            Address of first node
//    Output :           Boolean
//    Description :      Use to find out all elements are positive or not
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

bool CheckAllPositive(PNODE first)
{
    int iNo = 0;
    while(first != NULL)
    {
        iNo = first->Data;
        if((iNo % 2) != 0)
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
    bool bRet = 0;

    InsertFirst(&head,16);
    InsertFirst(&head,70);
    InsertFirst(&head,24);
    InsertFirst(&head,12);
    InsertFirst(&head,32);
    InsertFirst(&head,2);
    InsertFirst(&head,18);

    bRet = CheckAllPositive(head);

    if(bRet == true)
    {
        printf(" All elements are positive \n");
    }
    else
    {
        printf("All elements are not positive \n");
    }

    return 0;
}


