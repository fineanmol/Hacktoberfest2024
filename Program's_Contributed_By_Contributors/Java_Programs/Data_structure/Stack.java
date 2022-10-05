import java.util.Scanner;
class StackList{
    int info;
    StackList next,top=null;
    StackList(){
        next=null;
    }
    StackList(int info){
        this.info=info;
        next=null;
    }

    StackList push(int info){
        StackList n=new StackList(info);
        if(top==null){
            top=n;
            return top;
        }
        else{
            n.next=top;
            top=n;
            return top;
        }
    }

    StackList pop(){
        if(top==null){
            System.out.println("underflow");
            return top;
        }
        else{
            StackList temp=top;
            top=top.next;
            temp.next=null;
            return temp;
        }
    }

    int peek(){
        if(top==null){
            System.out.println("Underflow");
            return -1;
        }
        else{
            System.out.println(top.info);
            return top.info;
        }
    }

    void InsertAtBottom(StackList s,int x){
        int temp;
        if(s.top!=null){
            temp=s.pop().info;
            InsertAtBottom(s, x);
            s.push(temp);
        }
        else{
            s.push(x);
        }
    }

}

class StackArray{
    int arr[]=new int[100];
    int top=-1;
    void push(int info){
        if(top==arr.length-1){
            System.out.println("OverFlow");
            return;
        }
        top+=1;
        arr[top]=info;
    }

    void pop(){
        if(top==-1){
            System.out.println("underflow");
            return;
        }
        top=top-1;
    }

    int peek(){
        if(top==-1){
            System.out.println("UnderFlow");
            return -1;
        }
        System.out.println(arr[top]);
        return arr[top];
    }
}

class stackk {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        StackList f=new StackList();
        f.push(12);
        f.push(11);
        f.push(10);
        f.push(9);
        f.push(8);
        f.InsertAtBottom(f, 2);
        f.InsertAtBottom(f, 3);
        f.InsertAtBottom(f, 5);
        while(f.top!=null){
            System.out.print(f.pop().info+" ");
        }
        System.out.println();
        System.out.println("Enter Choice \n1.For Linked List Stack\n2.For Array Stack ");
        int ch=s.nextInt();
        switch(ch){
            case 1:
            StackList x=new StackList();
            x.push(2);
            x.push(3);
            x.peek();
            x.pop();
            x.peek();   
            break;
            case 2:
            StackArray a=new StackArray();
            a.push(12);
            a.peek();
            a.push(24);
            a.push(45);
            a.peek();
            a.pop();
            a.peek();
            a.pop();
            a.peek();
            break;
            default:System.out.println("Wrong choice");                     
        }
        s.close(); 
    }    
}
