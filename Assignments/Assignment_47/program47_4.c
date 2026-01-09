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
//    Function Name :    DisplayPrime
//    Input :            Address of first node
//    Output :           Display Prime numbers
//    Description :      Use to find out prime numbers from linked list
//    Author :           Ashwini Vishnu Kauthale
//    Data :             06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void DisplayPrime(PNODE first)
{
    printf("Prime numbers in Linked list are : ");
    int iCnt = 0;
    int iNo = 0;
    int iFlag = 0;
    while(first != NULL)
    {
        iNo = first->Data;
        iFlag = 0;
        if(iNo > 1)
        {
            for(iCnt = 2; iCnt <= iNo/2; iCnt++)
            {
                if((iNo % iCnt) == 0)
                {
                    iFlag = 1;
                    break;
                }
            }

            if(iFlag == 0)
            {
                printf("%d ",iNo);
            }
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

    InsertFirst(&head,15);
    InsertFirst(&head,30);
    InsertFirst(&head,23);
    InsertFirst(&head,11);
    InsertFirst(&head,37);
    InsertFirst(&head,7);
    InsertFirst(&head,18);

    DisplayPrime(head);

    return 0;
}


