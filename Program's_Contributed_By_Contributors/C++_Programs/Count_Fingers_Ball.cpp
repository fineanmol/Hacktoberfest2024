#include <iostream>
#include <math.h>
using namespace std;

int jari(float v)
{
    float r,a;
    a = 3*v / 12.57142857142857;
    r = pow(a,(float)1/3);
    return r;
}

int main()
{
    float volume, fingers;
    cout << "Insert How Much Volume Ball  = ";
    cin >> volume;
    cout << "================="<<endl;
    cout << "This Volume " << volume << " cm3" << endl;
    fingers = jari(volume);
    cout << "fingers-ball " << fingers << " cm";
    return 0;
}
