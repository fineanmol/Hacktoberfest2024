/*
Codeforces Problem 4/A

Problem Statement: One hot summer day Pete and his friend Billy decided to buy a watermelon. 
They chose the biggest and the ripest one, in their opinion. 
After that the watermelon was weighed, and the scales showed w kilos. 
They rushed home, dying of thirst, and decided to divide the berry, however they faced a hard problem.

Pete and Billy are great fans of even numbers, that's why they want to divide the watermelon in such a way that each of the two parts weighs even number of kilos, at the same time it is not obligatory that the parts are equal.
 The boys are extremely tired and want to start their meal as soon as possible, that's why you should help them and find out, if they can divide the watermelon in the way they want. 
 For sure, each of them should get a part of positive weight.
*/

#include<bits/stdc++.h>
//Problem 4/A
using namespace std;
int main(){
    int wt; //weight 
    cin>>wt;
    if(wt%2==0 && wt!=2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}