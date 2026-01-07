///////////////////////////////////////////////////////////////////////
//    Final code of Doubly Circuler Linked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode *next;
        DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Linked list gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T>* newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T>* newn = NULL;
    DoublyCLLnode<T>* temp = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    DoublyCLLnode<T>* newn = NULL;
    DoublyCLLnode<T>* temp = NULL;
    int iCnt = 0,iCount = 0;

    iCount = Count();

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout <<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }

    this->first->prev = this->last;
    this->last->next = this->first;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete first->prev;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    DoublyCLLnode<T>* temp = NULL;
    DoublyCLLnode<T>* target = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    
    this->iCount--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T>* temp = NULL;
    int iCnt = 0,iCount = 0;

    iCount = Count();

    if(pos < 1 || pos > this->iCount)
    {
        cout <<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }

    this->first->prev = this->last;
    this->last->next = this->first;
}

template<class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    DoublyCLLnode<T>* temp = first;

    cout<<"<=>";
    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp->next;
    } while(temp != first);

    cout<<"\n";
}

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

int main()
{
    DoublyCLL<float> *fobj = new DoublyCLL<float>();

    fobj->InsertFirst(51.54f);
    fobj->InsertFirst(21.56f);
    fobj->InsertFirst(11.89f);

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";


    fobj->InsertLast(101.67f);
    fobj->InsertLast(111.48f);
    fobj->InsertLast(121.90f);
    
    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->DeleteFirst();

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->DeleteLast();

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->InsertAtPos(105.67f,4);

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    fobj->DeleteAtPos(4);

    fobj->Display();
    cout<<"Number of elements are : "<<fobj->Count()<<"\n";

    delete fobj;
    
    return 0;
}
