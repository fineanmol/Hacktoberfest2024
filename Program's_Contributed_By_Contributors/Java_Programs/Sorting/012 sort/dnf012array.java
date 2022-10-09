package array;

public class dnf012array {
	{
        // code here 
        int ptrlow=0,ptrhigh=n-1,ptrmid=0;
        while(ptrmid<=ptrhigh){
            if(a[ptrmid]==0){
                int temp=a[ptrmid];
                a[ptrmid]=a[ptrlow];
                a[ptrlow]=temp;
                ptrlow++;
                ptrmid++;
            }
            if(a[ptrmid]==1){
                ptrmid++;
            }
            if(a[ptrmid]==2){
                 int temp=a[ptrmid];
                a[ptrmid]=a[ptrhigh];
                a[ptrhigh]=temp;
                
                ptrhigh--;
            }
            }
        }
}
