class ThreadClass extends Thread
{
    long counter = 0L;
    public void run()
    {
        while(true)
        {
            counter=counter+1;
        }
            
    }
    
}

class ThreadClassTwo extends Thread
{
    long countertwo = 0L;
    public void run()
    {
        while(true)
        {
            countertwo=countertwo+1;
        }
            
    }
    
    
}

public class Main
{
	public static void main(String[] args) {
	    
	    ThreadClass tc = new ThreadClass();
	    ThreadClassTwo tct = new ThreadClassTwo();
	    
	    System.out.println(tc.getName());
	    System.out.println(tct.getName());
	    System.out.println(tc.getPriority());
	    System.out.println(tct.getPriority());
	    
	    
	    System.out.println("changing values");
	    
	    
	    tc.setName("newthreadone");
	    tct.setName("newthreadtwo");
	    tc.setPriority(1);
	    tct.setPriority(10);
	    
	    
	    System.out.println(tc.getName());
	    System.out.println(tct.getName());
	    System.out.println(tc.getPriority());
	    System.out.println(tct.getPriority());
	    
	    tc.start();
	    tct.start();
	    
	    try 
	    {
	        Thread.currentThread().sleep(100);   
	    } 
	    catch(Exception e) 
	    {
	        System.out.println(e);   
	    } 
	   
		System.out.println("value of counter in ThreadClass: "+tc.counter);
		System.out.println("value of counter in ThreadClassTwo: "+tct.countertwo);
		
		tc.stop();
		tct.stop();
		
		
		
	}
}
