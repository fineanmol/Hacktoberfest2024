import java.util.*;
public class Controller extends Bike
{
    double b[]=new double[4];
    Controller(double X,double Y,double width,double length,double speed)
    {
    super(X,Y,width,length,speed);//length:along y axis ,width along X axis and the race is from X axis,along the Y axis       
    }
    public void reinit()
    {
     b[0]=X; //Xcenter
     b[1]=Y;  //yCenter
     b[2]=width;
     b[3]=length; 
    }
    public static boolean crashCheck(int [] b1, int [] b2) 
    {
 
     if((2*Math.abs(b1[0]-b2[0])<b1[2]+b2[2])&&(2*Math.abs(b1[1]-b2[1])<b1[3]+b2[3]))
     return true;
     else
     return false;
    }
     public static int winner(double [] b1, double [] b2)
     {
        if(b1[1]+b1[3]/2.0>b2[1]+b2[3]/2.0)
        return 1;
        else if(b1[1]+b1[3]/2.0<b2[1]+b2[3]/2.0)
        return 2;
        else
        return 3;
     }
     public static void main()
     {
        Scanner ob=new Scanner(System.in);
        System.out.println("Enter the width of first bike");
        double w1=ob.nextDouble();
        System.out.println("Enter the length of first bike");
        double l1=ob.nextDouble();
        System.out.println("Enter the speed of the first bike");
        double s1=ob.nextDouble();
        System.out.println("Enter the width of second bike");
        double w2=ob.nextDouble();
        System.out.println("Enter the length of second bike");
        double l2=ob.nextDouble();
        System.out.println("Enter the speed of the second bike");
        double s2=ob.nextDouble();
        System.out.println("Enter length of the race");
        double len=ob.nextDouble();
        Bike b1=new Controller(w1/2.0,-l1/2.0,w1,l1,s1);
        Bike b2=new Controller(w1+w2/2.0,-l2/2.0,w2,l2,s2);
        System.out.println("Enter the length of race");
        double length=ob.nextDouble();
        int c=1;
        while(true)
        {
            b1.posChangeUnitTime();
            b2.posChangeUnitTime();    
         int x=winner(((Controller)b1).b,((Controller)b2).b);
         if(x==1&&b1.Y+b1.length/2.0>=len)
         {
         System.out.println("Bike 1 has won the race");
         break;
        }
        else if(x==2&&b2.Y+b2.length/2.0>=len)
        {
         System.out.println("Bike 2 has won the race");
         break;
        }
        else if(x==3 && b1.Y+b1.length/2.0>=len && b2.Y+b2.length/2.0>=len)
        {
        System.out.println("Tie occured");
         break;
        }
        else
        {
        
        }
         System.out.println("After"+c+"seconds");
         System.out.println("Enter the speed of the first bike");
         double spd1=ob.nextDouble();         
         System.out.println("Enter the speed of the second bike");
         double spd2=ob.nextDouble();
         b1.changeSpeed(spd1);
         b2.changeSpeed(spd2);
         c++;
}
}
}
