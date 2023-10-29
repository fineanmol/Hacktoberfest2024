#include <iostream>
using namespace std;
class Base1
{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};
class Base2
{
protected:
    int base2int;

public:
    void set_base2int(int b)
    {
        base2int = b;
    }
};
class derived : public Base1, public Base2{
    public :
        void show(){
            cout << "The value of base 1 is " << base1int << endl;
            cout << "The value of base 2 is " << base2int << endl;
            cout << "The sum of base 1 and base 2 is " << (base1int + base2int) << endl;
        }
    };
int main()
{
    derived Ayush;
    Ayush.set_base1int(5);
    Ayush.set_base2int(50);
    Ayush.show();
    return 0;
}
