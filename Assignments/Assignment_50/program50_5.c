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
//    Function Name :    Display
//    Input :            Address of first node and and position
//    Output :           Display node
//    Description :      Use to find out node at given position
//    Author :           Ashwini Vishnu Kauthale
//    Data :             07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first,int no)
{
    int iPos = 0;
    int iNo = 0;
    while(first != NULL)
    {
        iNo = first->Data;
        iPos++;
        if(iPos == no)
        {
            printf("Element at Position %d is : %d",no,first->Data);
        }
        first = first->next;
    }
    if((no > iPos) || (no < 1))
    {
        printf("Invalid Position\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////
//    Entry Point function
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,70);
    InsertFirst(&head,40);
    InsertFirst(&head,35);
    InsertFirst(&head,32);
    InsertFirst(&head,2);
    InsertFirst(&head,18);

    int iPos = 0;

    printf("Enter the Position : \n");
    scanf("%d",&iPos);

    Display(head,iPos);

    return 0;
}


