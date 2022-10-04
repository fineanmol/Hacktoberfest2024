// Github username: AbhishekKumar2002
// Aim: Number Guessing Game 
// Date: 4/10/2022

// start coding
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num, guess, chance=0;
    num =rand()%100+1;
    cout<<"****Guess my number Game****\n";
    do
    {
        cout<<"Enter the number you guess between 1 and 100 : \n";
        cin>>guess;
        chance++;
        
        if (guess>num)
        {
            cout<<"The number you guessed is higher than the number\n";
            cout<<"Try Again!\n";
        }
        else if (guess<num)
        {
            cout<<"The number you guessed is smaller than the number \n";
            cout<<"Try Again!\n";
        }
        else
        {
            cout<<"Wohoo! you guess the write number\n";
            cout<<"You take chances are : "<<chance<<endl;
            cout<<"Your Score is :"<<101-chance<<endl;
        }
        
        
        

    } while (guess!=num);
    

    return 0;
}
