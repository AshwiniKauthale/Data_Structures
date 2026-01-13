#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void push(PPNODE first,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

int pop(PPNODE first)
{
    int Value = (*first)->data;
    PNODE temp = NULL;

    temp = *first;

    if(first == NULL)
    {
        printf("Stck is empty\n");
    }

    *first = (*first)->next;
    free(temp);

    return Value;
}

int peep(PPNODE first)
{
    int Value = (*first)->data;

    if(first == NULL)
    {
        printf("Stck is empty\n");
    }

    return Value;
}

void Display(PNODE first)
{
    if(first == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while(first != NULL)
    {
        printf("|  %d   |\n",first->data);
        first = first->next;
    }
}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    push(&head,101);
    push(&head,51);
    push(&head,21);
    push(&head,11);

    iRet = peep(&head);
    printf("Return value of peep is : %d\n",iRet);

    Display(head);
    iRet = Count(head);
    printf("Number of elements in stack are : %d\n",iRet);

    iRet = pop(&head);

    printf("Poped element is : %d\n",iRet);

    Display(head);
    iRet = Count(head);
    printf("Number of elements in stack are : %d\n",iRet);

    return 0;
}