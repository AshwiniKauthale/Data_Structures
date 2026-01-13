
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

class QueueX
{
    private node first;
    private node last;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void enqueue(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.iCount == 0)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
        }
        iCount++;
    }

    public int dequeue()
    {
        int Value = 0;
        Value = this.first.data;

        if((first == null) && (last == null))
        {
            System.out.println("Queue is empty\n");
            return 0;
        }
        else if(first == last)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
        }
        System.gc();
        this.iCount--;
        return Value;
    }

    public void Display()
    {
        node temp = null;

        if(first == null)
    {
        System.out.println("Queue is empty\n");
        return;
    }

        temp = this.first;
        while(temp != null)
        {
            System.out.println("|   "+temp.data+"    |");
            temp = temp.next;
        }
    }

    public int Count()
    {
        return this.iCount;
    }
}


class Queue
{
    public static void main(String A[])
    {
        QueueX sobj = new QueueX();

        int iRet = 0;

        sobj.enqueue(11);
        sobj.enqueue(21);
        sobj.enqueue(51);
        sobj.enqueue(101);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are : "+iRet);

        iRet = sobj.dequeue();
        System.out.println("Remover element is : "+iRet);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of elements are : "+iRet);
    }
}

