#include <iostream>
using namespace std;

int checkHarshad(int num){
    
    int sum = 0;
    int temp = num;
    
    while(temp != 0){
        sum = sum + temp % 10;
        temp /= 10;
    }
    
    // will return 1 if num is divisible by sum, else 0
    return num % sum == 0;
}

int main ()
{
    int n = 153;
    
    if(checkHarshad(n))
        cout << n << " is a Harshad's number";
    else
        cout << n << " is not a Harshad's number";

    return 0;
}
// Time complexity: O(N)
// Space complexity: O(1)
// Where N is the number of digits in number
