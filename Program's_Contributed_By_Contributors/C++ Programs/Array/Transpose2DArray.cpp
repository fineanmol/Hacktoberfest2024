#include <iostream>
using namespace std;
int main()
{
        int row,col;
        cout<<"Enter no of rows:";
        cin>>row;
        cout<<"Enter no of columns:";
        cin>>col;
        int**arr=new int*[row];
        for(int i=0;i<row;i++)
         arr[i]=new int[col];

        cout << "Enter elements in array:"<<endl;
         for(int i = 0 ; i < row ; i++)
         { 
            for(int j = 0 ; j < col ; j++)
                cin >> arr[i][j];
         }

        cout << endl << "Original array:" << endl;
         for (int i = 0; i < row; i++)
         {
             for (int j = 0; j < col; j++)
                 cout<<arr[i][j]<<"  ";
             cout << endl;
         }
         cout << endl << "Transpose of array:" << endl;
         for(int j=0; j<col; j++)
         {
             for(int i = 0; i<row; i++)
               cout << arr[i][j]<<" ";
             cout << endl;
         }

        for(int i=0;i<row;i++)
            delete[]arr[i];
        delete[]arr;
        arr=NULL;      
}
