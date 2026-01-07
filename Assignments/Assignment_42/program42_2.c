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
//    Input :            Data of node and Address of firstnode
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
//    Function Name :    SearchLastOcc
//    Input :            Data of node and Address of fiest node
//    Output :           Return the last position of element
//    Description :      Use to display last occurance of element
//    Author :           Ashwini Vishnu Kauthale
//    Data :             04/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int SearchLastOcc(PNODE first,int no)
{
    int iPos = 1;
    int iLastPos = 0;
    while(first != NULL)
    {
        if(first->Data == no)
        {
            iLastPos = iPos;
        }
        first = first->next;
        iPos++;
    }
    return iLastPos;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,70);
    InsertFirst(&head,30);
    InsertFirst(&head,50);
    InsertFirst(&head,40);
    InsertFirst(&head,30);
    InsertFirst(&head,20);
    InsertFirst(&head,10);

    int element = 0;

    printf("Enter element you want to search : ");
    scanf("%d",&element);

    iRet = SearchLastOcc(head,element);

    if(iRet == 0)
    {
        printf("Element is not found\n");
    }
    else
    {
        printf("Element fount at position : %d",iRet);
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Input  Linked List : | 10 |->| 20 |->| 30 |->| 40 |->| 50 |->| 30 |->| 70 |
//           Input Element      :  30
//           Output             :  6
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////