#include<iostream>
#include<cmath>
using namespace std;

class SimpleCalculator
{
    int num1, num2;
    public:
        void set_numbers_simple()
        {
            cout << "Enter the value of num1: ";
            cin >> num1;
            
            cout << "Enter the value of num2: ";
            cin >> num2;
        }

        void simple_operations()
        {
            cout << "The value of num1 + num2 is " << num1 + num2 << endl;
            cout << "The value of num1 - num2 is " << num1 - num2 << endl;
            cout << "The value of num1 * num2 is " << num1 * num2 << endl;
            cout << "The value of num1 / num2 is " << num1 / num2 << endl;
        }

};

class ScientificCalculator
{
    int num1, num2;
    public:
        void set_numbers_scientific()
        {
            cout << "Enter the value of num1: ";
            cin >> num1;
            
            cout << "Enter the value of num2: ";
            cin >> num2;
        }

        void scientific_operations()
        {
            cout << "The value of sin(num1) is " << sin(num1) << endl;
            cout << "The value of cos(num2) is " << cos(num2) << endl;
            cout << "The value of exp(num1) is " << exp(num1) << endl;
            cout << "The value of log(num2) is " << log(num2) << endl;
        }

};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{

};

int main()
{
    HybridCalculator h;
    cout << "This is simple " << endl;
    h.set_numbers_simple();
    h.simple_operations();
    cout << endl;
    cout << "This is scientific " << endl;
    h.set_numbers_scientific();
    h.scientific_operations();
    return 0;
}
