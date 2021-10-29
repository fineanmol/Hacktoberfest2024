#include <iostream>
#include <vector>
#include <utility>
//simple calculator for simple derivatives with a single term
using namespace std;

pair<int, int> derive(int exponent, int coefficient);


int main(){
    int expo, coeff, terms;
    vector<pair<int,int>> derivatives;
    cout << "Enter the number of terms you would like to derive: ";
    cin >> terms;
    int i = 0, x = 0; //iterators

    //asks the user for the coefficient and power of the term they want to derive and ports the resulting value into a vector as a pair
    while(i < terms){
        cout << "Enter the coefficient of term #" << i+1 << ": ";
        cin >> coeff;
        cout << "Enter the power of term #" << i+1 << ": ";
        cin >> expo;
        derivatives.push_back(derive(expo, coeff));

        i++;
    }

    //prints out all the terms
    cout << "Your terms are: " << endl;
    while(x < terms){
        cout << derivatives[x].first << "x^" << derivatives[x].second << endl;
        x++;
    }

    return 0;
}

pair<int, int> derive(int exponent, int coefficient){
    int ex, co;
    ex = exponent;
    co = coefficient;
    co *=  ex;
    ex -=1;

    pair<int,int> result (co, ex);

    return result;
}