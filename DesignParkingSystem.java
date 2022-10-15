class DesignParkingSystem {
    int big;
   int medium;
   int small;
   
   public DesignParkingSystem(int big, int medium, int small) {
       this.big=big;
       this.medium=medium;
       this.small=small;
   }
   
   public boolean addCar(int carType) {
       if(carType==1)
       {
           if(this.big>=1)
           {
               this.big-=1;
               return true;
           }
           else
           {
               return false;
           }
       }
       
         if(carType==2)
       {
           if(this.medium>=1)
           {
               this.medium-=1;
               return true;
           }
           else
           {
               return false;
           }
       }
       
           if(carType==3)
       {
           if(this.small>=1)
           {
               this.small-=1;
               return true;
           }
           else
           {
               return false;
           }
       }
       
       return true;
   }
}