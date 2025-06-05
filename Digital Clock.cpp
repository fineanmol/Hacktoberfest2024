#include <bits/stdc++.h>
#include<direct.h>
#include <conio.h>
#include<stdlib.h>
using namespace std;

void ch(){
    int h, m, sec, i;
    cout << "Enter the Current Time in the format hh mm ss";
    cin >> h >> m >> sec;

    while (h < 24)
    {

        while (m < 60)
        {

            while (sec < 60)
            {
                // system("CLS"); 
                // delay(1000);
                system("cls");
                cout << "hh mm sec";
                
                sec++;
                cout << h << ":" << m << ":" << sec << endl;
            }
            m++;
            sec = 0;
        }
        h++;
        m = 0;
    }
}

int main()
{

    

    ch();

    return 0;
}