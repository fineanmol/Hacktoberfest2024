#include<iostream>
#include<string>
using namespace std;

class Binary
{
    private:
        string s;
    public:
        void read();
        void check_binary();
        void compliment();
        void diaplay();
};

void Binary :: read()
{
    cout << "Enter a binary number: ";
    cin >> s;
}

void Binary :: check_binary()
{
    for (int i = 0; i < s.length(); i++)
    {
        if(s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect Binary Fromat!" << endl;
            exit(0);
        }
    }
    
}

void Binary :: compliment()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        
        else
        {
            s.at(i) = '0';
        }
    }
    
}

void Binary :: diaplay()
{
    cout << "Displaying your binary number: ";
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{
    Binary b;
    b.read();
    b.check_binary();
    b.diaplay();
    b.compliment();
    b.diaplay();
    return 0;
}
