#include<iostrem>
#include<conio>
using namespace std;

int main()
{
	int i = 1, j, k, rows;
    char ch;

    cout << "Enter Hollow Diamond Star Pattern Row = ";
    cin >> rows;

    cout << "Enter Symbol for Hollow Diamond Pattern = ";
    cin >> ch;

    while(i <= rows)
    {
        j = 1;
    	while( j <= rows - i)
		{
            cout << " ";
            j++;
        }
        k = 1;
        while( k <= i * 2 - 1)
        {
            if (k == 1 || k == i * 2 - 1)
            {
                cout << ch;
            }
            else
            {
                cout << " ";
            }
            k++;
        }
        cout << "\n";
        i++;
    }	

    i = rows - 1;
    while( i > 0)
    {
    	j = 1;
    	while( j <= rows - i)
		{
            cout << " ";
            j++;
        }
        k = 1;
        while( k <= i * 2 - 1)
        {
            if (k == 1 || k == i * 2 - 1)
            {
                cout << ch;
            }
            else
            {
                cout << " ";
            }
            k++;
        }
        cout << "\n";
        i--;
    }

 	return 0;
}