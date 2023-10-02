import java.util.*;

class node{
    int data;
    node next;
    node prev;
}

class DoublyLL{
    private int size;
    private node Head;

    public DoublyLL()
    {
        this.size = 0;
        this.Head = null;
    }

    public void Display()
    {
        node temp = Head;

        while(temp != null)
        {
            System.out.print("|"+temp.data+"|->");
            temp = temp.next;
        }
        System.out.println(" NULL");
    }

    public int Count()
    {
        return this.size;
    }

    public void InsertFirst(int no)
    {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            newn.next = Head;
            Head.prev = newn;
            Head = newn;
        }

        size++;
    }

    public void InsertLast(int no)
    {
        node newn = new node();
        node temp = Head;

        newn.next = null;
        newn.data = no;
        newn.prev = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            while(temp.next != null)
            {
                temp = temp.next;
            }
            newn.prev = temp;
            temp.next = newn;
        }
        size++;
    }

    public void DeleteFirst()
    {
        if(Head == null)
        {
            return;
        }
        else
        {
            Head = Head.next;
            Head.prev = null;
            System.gc();
        }
        size--;
    }

    public void DeleteLast()
    {
        node temp = Head;

        if(Head == null)
        {
            return;
        }
        else
        {
            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.prev.next = null;
            System.gc();
        }
        size--;
    }

    public void InsertAtPos(int no, int ipos)
    {
        int i = 0;
        node temp = Head;

        if((ipos < 1) || (ipos > (size + 1)))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == (size + 1))
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node();
            newn.data = no;
            newn.prev = null;
            newn.next = null;

            for(i = 1; i < (ipos - 1); i++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            newn.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;

            size++;
        }
    }

    void DeleteAtPos(int ipos)
    {
        node temp = Head;
        int i = 0;

        if((ipos < 1) || (ipos > size))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {
            DeleteLast();
        }
        else
        {
            for(i = 1; i < (ipos - 1); i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;
            System.gc();

            size--;
        }
    }
}

public class DoublyLinear{
    public static void main(String args[])
    {
        int iRet = 0;
        int iValue = 1;
        int iChoice = 0;
        int ipos = 0;

        Scanner sc = new Scanner(System.in);
        DoublyLL dobj = new DoublyLL();

        while(iValue != 0)
        {
            System.out.println("-------------------------------------------------------------");
            System.out.println(" 1 : Insert Element In The Linked List At First Position");
            System.out.println(" 2 : Insert Element In The Linked List At Last Position");
            System.out.println(" 3 : Insert Element In The Linked List At Desire Position");
            System.out.println(" 4 : Delete Element From The Linked List From First Position");
            System.out.println(" 5 : Delete Element From The Linked List From Last Position");
            System.out.println(" 6 : Delete Element From The Linked List From Desire Position");
            System.out.println(" 7 : Display Elements From The Linked List");
            System.out.println(" 8 : Count Elements From The Linked List");
            System.out.println(" 9 : Exit From The Application");
            System.out.println("-------------------------------------------------------------");
            System.out.println("Enter The Choice = ");
            iChoice = sc.nextInt();
    
            switch(iChoice)
            {
                case 1:
                    System.out.println("Enter The Value = ");
                    iValue = sc.nextInt();
                    dobj.InsertFirst(iValue);
                    break;
                case 2:
                    System.out.println("Enter The Value = ");
                    iValue = sc.nextInt();
                    dobj.InsertLast(iValue);
                    break;
                case 3:
                    System.out.println("Enter The Value = ");
                    iValue = sc.nextInt();
                    System.out.println("Enter The Position = ");
                    ipos = sc.nextInt(); 
                    dobj.InsertAtPos(iValue,ipos);
                    break;
                case 4:
                    dobj.DeleteFirst();
                    break;
                case 5:
                    dobj.DeleteLast();
                    break;
                case 6:
                    System.out.println("Enter The Position = ");
                    ipos = sc.nextInt();
                    dobj.DeleteAtPos(ipos);
                    break;
                case 7:
                    dobj.Display();
                    break;
                case 8:
                    iRet = dobj.Count();
                    System.out.println("The Elements From The Linked List Are = "+iRet);
                    break;
                case 9:
                    System.out.println("Thank You For Using Marvellous Linked List");
                    iValue = 0;
                    break;
                default:
                    System.out.println("Please Enter An Valid Choice !");
                    break;
            }
        }
        sc.close();
    }
}