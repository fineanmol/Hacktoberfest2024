#include <iostream>
using namespace std ;

void PrintArray(int arr[] , int size)
{
    for (int  i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl ;
}
int main()
{
    cout<<"Enter the size of the array you want to make "<<"\n";
    int siz ; 
    cin>>siz ;
    int array[siz];
    for(int i =0 ; i < siz ; i++)
    {
        cin>>array[i];
    }
    cout<<"The array before Sorting "<<"\n";
    PrintArray(array , siz);
    //--------Exchange Sorting --------//
    for(int i = 0 ; i < siz - 1  ; i++)
    {
        for(int j = i+1 ; j < siz ;j++)
        {
            if(array[i] > array[j]) // swap if the condition is true 
            {
                int temp = array[i] ;
                array[i] = array[j] ; 
                array[j] = temp ;
            }
        }
    }
    cout<<"The array after Sorting "<<"\n";
    PrintArray(array , siz);
    return 0;
}
