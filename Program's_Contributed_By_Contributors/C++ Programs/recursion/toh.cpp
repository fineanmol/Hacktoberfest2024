#include<iostream>
using namespace std;
 
void toh(int n, char from,char to, char aux)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, from, aux, to);
    cout << "Move : " << n << " from  " << from << " to  " << to << endl;
    toh(n - 1, aux, to, from);
}
 
int main()
{
   
    toh(5, 'A', 'C', 'B'); 
   
}