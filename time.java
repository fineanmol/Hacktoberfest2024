class TestMain{
      public static void main (String args[]){
                  Time t1 = new Time();
                  Time t2 = new Time(14,44,25);
                  Time t3 = new Time(8,44,25);
                  t2.printer();
                  t3.printer();
      }
}
 
 
 
 
 

class Time{
      int Hrs;
      int Mins;
      int Secs;
      public Time(){
                  Hrs = 0;
                  Mins = 0;
                  Secs = 0;
      }
      public Time(int hrs , int mins , int secs){
                  this.Hrs = hrs;
                  this.Mins = mins;
                  this.Secs = secs;
      }
      public void printer(){
                  if(Hrs >= 12)
                              System.out.println((Hrs-12)+":"+Mins+":"+Secs+"PM");
                  else
                              System.out.println(Hrs+":"+Mins+":"+Secs+"AM");
      }           
}

 








