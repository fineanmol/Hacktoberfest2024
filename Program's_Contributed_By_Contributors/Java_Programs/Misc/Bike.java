public class Bike
{
    double X,Y,length,width,speed;
    Bike(double X,double Y,double width,double length,double speed)
    {
    this.X=X;
    this.Y=Y;
    this.length=length;
    this.width=width;
    this.speed=speed;
   }
    public void changeSpeed(double spd)
    {
     speed=speed+spd;
     if(speed<0)
     {
        speed=Math.abs(speed);
     }
    }
    public void posChangeUnitTime()
    {
    Y=Y+speed*1;
    }
    public double getYPosition() 
    {
    return Y;
    }
}