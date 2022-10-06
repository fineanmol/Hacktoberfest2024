#include<iostream>
using namespace std;

void tower_of_hanoi(int n,char from_rod,char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<" to rod " << to_rod<<endl;
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod); // shifting n-1 discs from 'A' to 'B'
    cout << "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod <<endl; 
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod); //shifting n-1 discs from 'B' to 'C'
}

int main()
{
    int n;
    cout<<"ENTER NO. OF DISCS:";
    cin>>n;
    tower_of_hanoi(n,'A','C','B');
}