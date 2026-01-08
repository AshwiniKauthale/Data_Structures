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
//    Function Name :    CountGreater
//    Input :            Data of node and Addresss of first node
//    Output :           Integer
//    Description :      Use to Count element greater than given elemenet
//    Author :           Ashwini Vishnu Kauthale
//    Data :             05/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int CountGreater(PNODE first,int no)
{
    int iCount = 0;
    while(first != NULL)
    {
        if(first->Data > no)
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

    InsertFirst(&head,11);
    InsertFirst(&head,30);
    InsertFirst(&head,51);
    InsertFirst(&head,11);
    InsertFirst(&head,37);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    int element = 0;

    printf("Enter number : \n");
    scanf("%d",&element);

    iRet = CountGreater(head,element);

    printf("elements grater than %d are : %d",element,iRet);

    return 0;
}


