import java.util.Scanner;
public class Stack
  {
    int s[];
    int size,top;
    public Stack(int n)
      {
         s=new int[size=n];
         top=-1;
      }
    public void push(int d)
       {
        if(top==size-1)
          System.out.println("Overflow");
        else
          s[++top]=d;
       }
   public void peek()
     {
       if(top==-1)
         System.out.println("Underflow");
       else
         {
            for(int i=top;i>=0;i--)
              {
                System.out.printf("%4d",s[i]);  
              }
           System.out.println();   
         }
     }
   public void pop()
      {
          if(top==-1)
             System.out.println("Underflow");
          else
             {
               System.out.println(s[top]+" is deleted");
               top--;
               
             }
        
      }
   public static void main(String args[])
     {
        Scanner sc=new Scanner(System.in);
        Stack ob=new Stack(3);
        int ch;
        do{
             System.out.println("1.Push\n2.Peek\n3.Pop\n4.Exit");
             System.out.print("Enter your choice:- ");
             ch=sc.nextInt();
             switch(ch)
               {
                  case 1:System.out.print("Enter data :- ");
                          int data=sc.nextInt();
                          ob.push(data);
                          break;
                  case 2:ob.peek();
                         break;
                  case 3:ob.pop();
                          break;
                  case 4: System.exit(1);
                  default:System.out.println("Invalid choice");
               }
          }while(ch!=4);
     }
  }