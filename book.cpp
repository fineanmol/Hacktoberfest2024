#include <bits/stdc++.h>
using namespace std;
class books
{
public:
    char *author, *title, *pub;
    int price, cop;
    static int c;
    books(const char *auth, const char *tit, int pr, const char *pb, int pos)
    {
        this->author = new char[strlen(auth) + 1];
        strcpy(this->author, auth);
        this->title = new char[strlen(tit) + 1];
        strcpy(this->title, tit);
        this->pub = new char[strlen(pb) + 1];
        strcpy(this->pub, pb);
        this->price = pr;
        this->cop = pos;
    }
    int search(const char *auth, const char *tit, int pos)
    {

        float Cost = price * pos;
        cout << "Book Details:" << endl;
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Price per copy: $" << this->price << endl;
        cout << "Publisher: " << this->pub << endl;
        cout << "Available Copies: " << this->cop << endl;
        cout << "Total Cost for " << pos << " copies: $" << Cost << endl
             << endl;
        return 1;
    }
    void fun(const char *auth, const char *tit, int pos)
    {
        int res = -1;

        if (strcmp(author, auth) == 0 && strcmp(title, tit) == 0)
        {
            if (cop >= pos)
            {
                search(auth, tit, pos);
                res = 1;
            }
            return;
        }
        c++;
        if (c == 3)
        {

            cout << "\nNot found" << endl
                 << "Transaction Unsuccessful" << endl;
        }
    }
};
int books::c = 0;
int main()
{
    int res = -1;
    books b[3] = {
        books("Ram", "Gopal", 79, "DS", 50),
        books("Raj", "Giri", 79, "DL", 50),
        books("Raj", "Sham", 79, "DM", 50)};
    char auth[20], tit[20], c;
    int pos;
    for (int i = 0; i < 3; i++)
    {
        b[i].fun("Ram", "Gopal", 30);
    }
    books::c = 0;
    for (int i = 0; i < 3; i++)
    {
        b[i].fun("Raj", "Giri", 30);
    }
    books::c = 0;
    for (int i = 0; i < 3; i++)
    {
        b[i].fun("Raj", "Shyam", 30);
    }
    books::c = 0;
}