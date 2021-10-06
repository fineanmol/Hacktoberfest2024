#include <iostream>
#include <vector>

using namespace std;

// Convert an integer to roman numeral
string intToRoman(int num) 
{
    vector<string> thousands = {"", "M", "MM", "MMM"};
    vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        
    int thousandsPlace = num / 1000;
    int hundredsPlace = (num % 1000) / 100;
    int tensPlace = (num % 100) / 10;
    int onesPlace = num % 10;
        
    string result = thousands.at(thousandsPlace) + hundreds.at(hundredsPlace) + tens.at(tensPlace) + ones.at(onesPlace);
        
    return result;
}
    
int main()
{
    // Driver code
    int value = 0;
    
    cout<<"Enter an integer: ";
    cin >> value;
    cout << endl;
    cout << intToRoman(value) << endl;

    return 0;
}
