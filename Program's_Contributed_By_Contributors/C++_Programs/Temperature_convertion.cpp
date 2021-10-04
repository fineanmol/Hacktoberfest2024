#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
    int i;
    float cel,rea,fah;
    cout << "== Tempererature Convertion ==\n" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
    cout << "|| Celcius  ||" << "    Reamur || " << "   Fahrenheit ||" << endl;
    for (i=1; i<=100; i++ ){
        cel=i;
        rea=i*0.8;
        fah=1.8*i+32;
        cout << "||     " << cel << "    ||     " << rea << "    ||      " << fah << "   ||      " << endl;
    }
    system ("color 37");
    getch();
    return 0;
}
