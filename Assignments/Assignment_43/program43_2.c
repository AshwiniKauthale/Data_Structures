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
//    Function Name :    DisplayPrime
//    Input :            Address of first node
//    Output :           Display Prime number
//    Description :      used to find out prime numbers from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             04/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

int DisplayPrime(PNODE first)
{
    int iCnt = 0;
    int iCount = 0;

    printf("Prime numbers in linklist are : ");

    while(first != NULL)
    {
        iCount = 0;
        if(first->Data > 1)
        {
            for(iCnt = 2;iCnt <= first->Data/2;iCnt++)
            {
                if((first->Data % iCnt) == 0)
                {
                    iCount++;
                    break;
                }
            }
            if(iCount == 0)
            {
                printf("%d ",first->Data);
            }
        first = first->next;
        }
    
    }
    printf("\n");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    InsertFirst(&head,89);
    InsertFirst(&head,22);
    InsertFirst(&head,41);
    InsertFirst(&head,17);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    DisplayPrime(head);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           Input  Linked List : | 11 |->| 20 |->| 17 |->| 41 |->| 22 |->| 89 |
//           Output             :  11  17  41  89
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
