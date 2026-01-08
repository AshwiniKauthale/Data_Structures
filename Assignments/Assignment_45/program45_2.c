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
//    Data :             05/01/2026
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
//    Function Name :    FirstOccur
//    Input :            Data of node and Address of first node
//    Output :           Integer
//    Description :      Use to find out first occurance of given element
//    Author :           Ashwini Vishnu Kauthale
//    Data :             05/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int FirstOccur(PNODE first,int no)
{
    int iPos = 1;
    while(first != NULL)
    {
        if(first->Data == no)
        {
            return iPos;
        }
        iPos++;
        first = first->next;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,11);
    InsertFirst(&head,30);
    InsertFirst(&head,51);
    InsertFirst(&head,11);
    InsertFirst(&head,37);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    int element = 0;

    printf("Enter element you want to find\n");
    scanf("%d",&element);

    iRet = FirstOccur(head,element);

    if(iRet == 0)
    {
        printf("Element is not found\n");
    }
    else
    {
        printf("First Occured at Position : %d",iRet);
    }

    return 0;
}


