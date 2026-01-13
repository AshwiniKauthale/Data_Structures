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

void enqueue(PPNODE first,PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
    }
}

int dequeue(PPNODE first,PPNODE last)
{
    int Value = 0;
    Value = (*first)->data;
    PNODE temp = NULL;
    if((*first == NULL) && (*last == NULL))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);
    }
    return Value;
}

void Display(PNODE first)
{
    if(first == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    while(first != NULL)
    {
        printf("|   %d     |",first->data);
        first = first->next;
    }
}

int Count(PNODE first)
{
    PNODE temp = NULL;
    int iCount = 0;
    if(first == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }

    temp = first;
    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iRet = 0;

    enqueue(&head,&tail,101);
    enqueue(&head,&tail,101);
    enqueue(&head,&tail,51);
    enqueue(&head,&tail,21);
    enqueue(&head,&tail,11);

    Display(head);
    iRet = Count(head);
    printf("Number of elements in Queue are : %d\n",iRet);

    iRet = dequeue(&head,&tail);
    printf("Removed element is : %d\n",iRet);


    Display(head);
    iRet = Count(head);
    printf("Number of elements in Queue are : %d\n",iRet);

    return 0;
}
