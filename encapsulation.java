public class encapsulation {
    public static void main(String[] args) {
        int a=157;
        C2 e=new C2();
        e.setC(a);
        System.out.println(e.getC().f);
        System.out.println(e.d.f);
        e.setCasD();
        System.out.println(e.getC().f);
        System.out.println(e.d.f);
        e.setCasB();//c = b
        e.d.f=79;// resetting value of d.f
        System.out.println(e.getC().f);//45
        System.out.println(e.d.f);//79
    }
}

class C2{
    private C3 c=new C3();
    private final C3 b=new C3();//it is final instance of c3 and cannot be changed
    C3 d=new C3();

    public C3 getC(){
        return c;
    }
    public void setC(int a){
        if (a<100) {
            c.f = a;
        }else{
            c.f=99;
        }
    }
    public void setDasC(){
        d=c;
    }
    public void setCasD(){
        c=d;
    }
    public void setCasB(){
        c=b;//The final field C2.b cannot be assigned
    }

}

class C3{
    int f=45;
}