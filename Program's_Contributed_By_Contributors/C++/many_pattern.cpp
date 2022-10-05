#include<iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int rows, columns;
    cin>>rows>> columns;

    cout<<"Pattern 1 :- Rectangle\n"<< endl;
    for(int i = 1 ; i <= rows; i++)
    {
        for(int j = 1 ; j <= columns; j++ )
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 2 :- Hollow Rectangle\n"<<endl;
    for(int i = 1 ; i <= rows; i++)
    {
        for(int j = 1 ; j <= columns; j++ )
        {
            if(j == 1 || j == columns || i == 1 || i == rows)
                cout<<"* ";
            else{
                cout<<"  ";
            }
            
        }
        cout<<endl;
    }

    cout<<"\nPattern 3 :- Inverted half Pyramid\n"<<endl;
    for(int i = rows ; i >= 1; i--)
    {
        for(int j = 1 ; j <= i; j++ )
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 4 :- half Pyramid after 180 deg rotation\n"<<endl;
    for(int i = rows ; i >= 1; i--)
    {
        for(int j = 1 ; j <= rows; j++ )
        {
            if(j < i)
                cout<<"  ";
            else
                cout<<"* ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 5 :- Half Pyramid using numbers\n"<<endl;
    for(int i = 1 ; i <= rows; i++)
    {
        for(int j = 1 ; j <= i; j++ )
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 6 :- Butterfly pattern\n"<<endl;
    for(int i = 1 ; i <= rows * 2; i++)
    {
        for(int j = 1 ; j <= rows * 2; j++ )
        {
            if((j <= i || j > (rows * 2)- i) && i <= rows)
                cout<<"* ";

            else if ((j >= i || j <= (rows * 2)- (i - 1)) && i > rows)
                cout<<"* ";
            
            else
                cout<<"  ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 7 :- Inverted half Pyramid using numbers\n"<<endl;
    for(int i = rows ; i >= 1; i--)
    {
        for(int j = 1 ; j <= i; j++ )
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 8 :- Half Pyramid using 0/1\n"<<endl;
    for(int i = 1 ; i <= rows; i++)
    {
        for(int j = 1 ; j <= i; j++ )
        {
            if ((i + j) % 2 == 0)
                cout<<"1 ";

            else
                cout<<"0 ";
        }
        cout<<endl;
    }

    cout<<"\nPattern 9 :- Rombus\n"<<endl;
    for(int i = 1 ; i <= rows; i++)
    {
        for(int j = 1 ; j <= rows - i; j++ )
        {
            cout<<"  ";
        }
        for(int j = 1; j <= rows; j++ )
        {
            cout<<"* ";
        }
        cout<<endl;
    }


    return 12;

}
