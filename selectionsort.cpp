#include<iostream>
using namespace std;
class test{
    private:
    int a,b,c;
    public:
    void getdata(int x, int y,int z);
    void operator -();
    void display();
};
void test:: getdata(int x, int y, int z)
{
    a=x;
    b=y;
    c=z;
}
void test::operator -()
{
    a=-a;
    b=-b;
    c=-c;

}
void test:: display()
{
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
    cout<<"C: "<<c<<endl;
}
int main()
{
    test t;
    t.getdata(4,-6,1);
    t.display();
    -t;
    t.display();

    return 0;
}
