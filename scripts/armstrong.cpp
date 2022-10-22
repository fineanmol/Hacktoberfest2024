/* The following code is used to check Armstrong number of n digits

A positive integer is called an Armstrong number (of order n) if

abcd... = an + bn + cn + dn + ...
 
*/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
   int num, originalNum, remainder, n = 0, result = 0, power;
   cout << "Enter an integer: ";
   cin >> num;

   originalNum = num;

   while (originalNum != 0) {
      originalNum /= 10;
      ++n;
   }
   originalNum = num;

   while (originalNum != 0) {
      remainder = originalNum % 10;

      // pow() returns a double value
      // round() returns the equivalent int
      power = round(pow(remainder, n));
      result += power;
      originalNum /= 10;
   }

   if (result == num)
      cout << num << " is an Armstrong number.";
   else
      cout << num << " is not an Armstrong number.";
   return 0;
}

/*output

Enter an integer: 1634
1634 is an Armstrong number.

*/