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
//    Function Name :    SecMaximum
//    Input :            Address of first node
//    Output :           Return second maximum element
//    Description :      Use to find out second maximum element from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             04/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int SecMaximum(PNODE first)
{
    int iMax, iSecMax;

    if (first == NULL || first->next == NULL)
    {
        return -1;
    }

    iMax = first->Data;
    PNODE temp = first;

    while (temp != NULL)
    {
        if (temp->Data > iMax)
        {
            iMax = temp->Data;
        }
        temp = temp->next;
    }

    iSecMax = -1;
    temp = first;

    while (temp != NULL)
    {
        if ((temp->Data < iMax) && (temp->Data > iSecMax))
        {
            iSecMax = temp->Data;
        }
        temp = temp->next;
    }

    return iSecMax;
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

    iRet = SecMaximum(head);

    printf("Second Largest elements is : %d",iRet);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Input  Linked List : | 110 |->| 230 |->| 322 |->| 240 |
//           Output             :  240
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
