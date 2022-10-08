/*
Name : Rounak Ghosh
Username : Rounak-Ghosh
About : 4th year undergrad student at GCETTB
*/

#include<iostream>
#include<string>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) !=0);
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

int main()
{
    int n, pos, value;
    cin >> n >> pos >> value;

    cout << getBit(n, pos) << endl;
    cout << setBit(n, pos) << endl;
    cout << clearBit(n, pos) << endl;
    cout << updateBit(n, pos, value) << endl;

    return 0;
}