import java.io.*;
public static void main(String [args]){
        double sum=0,i=0;
       int n=10;
        if(n==0){
            return 1;
        }
        while(n!=0){
            int d=n%2;
            
            if(d==1){
                sum=sum+0*Math.pow(2,i);
            }
            else{
                sum=sum+1*Math.pow(2,i);
            }
            i++;
            n=n/2;
        }
        return (int)Math.round(sum);
        
    }