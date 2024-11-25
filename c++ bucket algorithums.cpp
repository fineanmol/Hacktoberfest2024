#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    float arr[10] ;
    int i,n;
    cout<< "Enter the number of elements :\n";
	cin>>n;
	cout<<"Enter the elements:\n";
    for (i=0;i<n;i++)
    { 
      cin>>arr[i];
    }


	//sorting arr[] of size n using bucket sort 

    std::vector<float> bucket[n];// Create n empty buckets  

    //Put values in different buckets 
    for (int i=0; i<n; i++) 
    { 
       int bi = n*arr[i]; // Index in bucket 
       bucket[bi].push_back(arr[i]); 
    } 

    //Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(bucket[i].begin(), bucket[i].end()); 


    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < bucket[i].size(); j++) 
          arr[index++] = bucket[i][j]; 

    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
    return 0; 
}

/*
Input: 
Enter the number of elements :
4
Enter the elements:
0.123
0.008
0.7
0.4
Output:
Sorted array is 
0.008 0.123 0.4 0.7
*/
