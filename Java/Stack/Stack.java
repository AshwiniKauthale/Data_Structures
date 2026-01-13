
class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class StackX
{
    private node first;

    private int iCount;

    public StackX()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void push(int no)
    {
        node newn = null;

        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public int pop()
    {
        node temp = null;

        if(this.iCount == 0)
        {
            System.out.println("Stack is empty");
            return -1;
        }

        temp = this.first;
        int Value = first.data;

        this.first = this.first.next;
        System.gc();

        this.iCount--;
        return Value;
    }

    public int peep()
    {
        int Value = first.data;

        if(this.iCount == 0)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        return Value;
    }

    public void Display()
    {
        node temp = null;
        if(this.iCount == 0)
        {
            System.out.println("Stack is empty\n");
            return;
        }

        temp =this.first;
        while(temp != null)
        {
            System.out.println("|   "+temp.data+"   |");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return this.iCount;
    }
}

class Stack
{
    public static void main(String A[])
    {
        StackX sobj = new StackX();

        int iRet = 0;

        sobj.push(11);
        sobj.push(21);
        sobj.push(51);
        sobj.push(101);

        iRet = sobj.peep();
        System.out.println("Return value of peep is : "+iRet);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are : "+iRet);

        iRet = sobj.pop();
        System.out.println("Poped element is : "+iRet);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are : "+iRet);
    }

}