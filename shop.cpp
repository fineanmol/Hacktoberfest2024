#include<iostream>
using namespace std;

class Shop
{
    private:
        int itemId[10];
        int itemPrice[10];
        int counter;
    public:
        void initCounter() {counter = 0;}
        void setPrice();
        void displayPrice();
};

void Shop :: setPrice()
{
    cout << "Enter the Id of your item no. " << counter + 1 << " : ";
    cin >> itemId[counter];
    cout << endl;
    cout << "Enter the Price of your item no. " << counter + 1 << " : ";
    cin >> itemPrice[counter];
    cout << endl;
    counter++;
}

void Shop :: displayPrice()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
    
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}
