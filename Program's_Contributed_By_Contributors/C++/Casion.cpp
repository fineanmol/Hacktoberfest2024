#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
void terms();
int main()
{
    string Player;
    int balance; // stores player's balance
    int bettingAmount;
    int guess, My_rand;
    int craps; // stores the random number;just like dice
    char choose;
    srand(time_t(0));//seed random number; I used it for unique id for casino player.
    My_rand = rand();
    cout <<rand() << "-Unique Customer ID ";//if any problem occurs use this unique id for assistance.
    cout << "\n\t\t  ========WELCOME TO CASINO WORLD======= ";
    cout << "\n\nType your Name : ";
    getline(cin, Player);
    cout<< "\t Disclaimer: Gambling may not be safe for person. It leads to addiction. Be Smart and Aware. We take no resposibility.";
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        terms();
        cout << "\n\nYour current balance is $ " << balance << "\n";
        // Get player's betting balance
        do
        {
            cout << "Hey, " << Player<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
            cout << "Betting balance can't be more than current balance!\n"<<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
        // Get player's numbers
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        craps = rand()%10 + 1;
        if(craps == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << craps <<"\n";
        cout << "\n"<<Player<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have Insufficient Balance ";
            break;
        }
        cout << "\n\n-->Do you want to bet again (y/n)? ";
        cin >> choose;
    }while(choose =='Y'|| choose=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
void terms()
{
    cout << "\n\n======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

