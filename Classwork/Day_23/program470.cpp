#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int  *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside Constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside Destrector\n";
            delete []Arr;
        }
};

int main()
{
    ArrayX aboj(10);

    return 0;
}