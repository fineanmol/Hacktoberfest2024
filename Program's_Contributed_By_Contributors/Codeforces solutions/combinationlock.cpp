/*
CodeForces problem 540/A

Problem Statement:  Scrooge McDuck keeps his most treasured savings in a home safe with a combination lock.
 Each time he wants to put there the treasures that he's earned fair and square, he has to open the lock.

The combination lock is represented by n rotating disks with digits from 0 to 9 written on them. 
Scrooge McDuck has to turn some disks so that the combination of digits on the disks forms a secret combination. 
In one move, he can rotate one disk one digit forwards or backwards. 
In particular, in one move he can go from digit 0 to digit 9 and vice versa.
 What minimum number of actions does he need for that?
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,val1,val2;
    int diff1,diff2,diff,sum=0;
    cin>>n;// the number of disks on the combination lock.
    string s1,s2; //s1: the original state of the disk
    cin>>s1>>s2;// s2: the Scrooge McDuck's combination that opens the lock.
    for(i=0;i<n;i++){
        val1=(int)(max(s1[i],s2[i]));
        val2=(int)(min(s1[i],s2[i]));
        diff1=val1-val2;
        diff2=(val2-0)+(9-val1+1);
        diff=min(diff1,diff2);
        
        sum+=diff;
        
        
    }
    cout<<sum;
}