#include<iostream>
#include<climits>

using namespace std;

    int getmin (int num[], int  size){

        int min =INT_MAX;

        for(int i=0; i<size; i++){
            if(num[i]< min){
                min= num[i];
            }
        }
        return min;
    }

    int getmax(int num[] , int size){

        int max = INT_MIN ;

        for(int i=0; i< size; i++){
            if(num[i] > max){
                max = num[i]; 
            }
        }
        //Returning max value 
        return max;
    }
    


  int main(){
      //Bad Practice
  
    int size;
    cout<<"Size"<<endl;
    cin>>size;
    cout<<"Enter the input values"<<endl;

    // int array[size];    //bad Practice 
      
    int num[100];        //this is still acceptable
    for(int i =0; i<size; i++){
        cin>>num[i];               //input aise lena 
    }

    cout<<"The max value is " <<getmax(num, size)<<endl;
    cout<<"The min value is " <<getmin(num, size)<<endl;


  return 0;
 }