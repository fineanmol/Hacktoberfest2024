// Created by Fatao
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";
int size = sizeof(alphanum) - 1;
int main()
{
    //password length
    int length = 12;
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        cout << alphanum[rand() % ::size];
    }
    return 0;
}