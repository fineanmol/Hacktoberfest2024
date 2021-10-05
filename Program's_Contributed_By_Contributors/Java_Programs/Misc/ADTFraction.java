public class ADTFraction {
	
    public static void main(String[] args) {
        // TODO code application logic here
        ADTFractionTest f1= new  ADTFractionTest(1, 2);
        f1.display();
        ADTFractionTest f2=new  ADTFractionTest(3,8);
        ADTFractionTest f3= f1.plus(f2);
       f3.display();
         
    }
}

class ADTFractionTest {
 private int n; //numerator
 private int d; //denomenator 
//---------------------------------------------------
 public ADTFraction() {//default constructor 
 this.n=0;
 this.d=1;
 }
//---------------------------------------------------
 public ADTFraction(int a, int b) {//parameter constructor 
if(b!=0){
    this.n=a;
    this.d=b;
}else{
    this.n=0;
    this.d=1;
    System.out.println("denominator cannot be zero");
}
  
 }
//---------------------------------------------------
 public void set(int a, int b) {//set numerator and denomenator 
this.n=a;
this.d=b;
 }
//---------------------------------------------------
 public ADTFraction plus(ADTFraction x) {//add two fractions
     int num,denm;
     num=this.n*x.d;
     denm=this.d*x.n+this.n*x.d;
     ADTFraction f1=new ADTFraction(num, denm);
     return f1;
 }
//---------------------------------------------------
 public ADTFraction times(int a) {//multiply fraction by a number
 int num=a*this.n;
 int denm=this.d;
 ADTFraction f2=new ADTFraction(num, denm);
 return f2;
 
 }
 //---------------------------------------------------
 public ADTFraction times(ADTFraction x) {//multiply two fractions
 int num,denm;
 num=this.n*x.n;
 denm=this.d*x.d;
 ADTFraction f3=new ADTFraction(num,denm);
 return f3;
 
 } 
//---------------------------------------------------
 public ADTFraction reciprocal() {//reciprocal of a fraction
     ADTFraction f4=new ADTFraction(this.d, this.n);
     return f4;
 }
//---------------------------------------------------
 public float value() {//numerical value of a fraction
     return (float)this.n/this.d;
 }
//---------------------------------------------------
 public void display() {//display the fraction in the format n/d
     System.out.println(this.n+"/"+this.d);
 }
//---------------------------------------------------
 
}
