// Doubly Circular

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    
    private int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL gets created.");
        
        this.first = null;
        this.last = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        // Chnged code
        newn = new node(no);

        if((this.first == null) && (this.last == null))
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            newn.next = this.first;
            this.first.prev = newn;
            this.first = newn;
        }

        this.last.next = this.first;
        this.first.prev = this.last;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.last.next = newn;
            newn.prev = this.last;
            this.last = newn;
        }
        this.last.next = this.first;
        this.first.prev = this.last;


        this.iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0,iCount = 0;

        iCount = Count();

        if(pos < 1 || pos > this.iCount + 1)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new node(no);

            newn.data = no;
            newn.next = null;

            temp = this.first;

            for(iCnt = 1;iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.prev = newn.next;
            temp.next = newn;
            newn.prev = temp;
        }
        this.last.next = this.first;
        this.first.prev = this.last;

        this.iCount++;
    }

    public void DeleteFirst()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if((this.first == this.last))
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            temp = this.first;

            this.first = this.first.next;

            this.last.next = this.first;
            this.first.prev = this.last;

        }
        System.gc();
        this.iCount--;
    }
    
    public void DeleteLast()
    {
        node temp = null;

        if((this.first == null) && (this.last == null))
        {
            return;
        }
        else if((this.first == this.last))
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.last = this.last.prev;

            this.last.next = this.first;
            this.first.prev = this.last;

        }
        System.gc();
        this.iCount--;
    }
    
    public void DeleteAtPos(int pos)
    {
        node temp = null;
        node target = null;


        int iCnt = 0;

        if(pos < 1 || pos > this.iCount + 1)
        {
            System.out.println("Invalid position");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == iCount+1)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1;iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;
            temp.next = target.next;

            this.iCount--;
        }
        System.gc();

        this.last.next = this.first;
        this.first.prev = this.last;
    }
    
    public void Display()
    {
        if(first == null)
            {
                System.out.println("Linked list is empty\n");
                return;
            }

            node temp = first;

            System.out.print("<=>");
            do
            {
                System.out.print(" | "+temp.data+" | <=>");
                temp = temp.next;
            } while(temp != first);

            System.out.println();
    }

    public int Count()
    {
        return this.iCount;
    }
}

class DoublyCirculer
{
    public static void main(String A[])
    {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}