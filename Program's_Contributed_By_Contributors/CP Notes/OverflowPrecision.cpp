/*
So the concept of overflow can be seen in competative coding a lot, the worst probelm of not understanding it is , writing 
a completely perfect code but Still getting wrong answer, this is because at higher input ranges, the compiler strips down
the result as per the data size hence its important to remember the basic ranges of data types.

a) Int => [-10^910^9]
b) Long Int / long => [-10^12,10^12]
c) Long Long Int / long long => [-10^18,10^18]
*/

#include<bits/stdc++.h>
using namespace std; 

int main(){

//An example of overflow
int a = 100000, b = 100000;
int c = a*b; //Expected answer ? 10^10 but no the answer you get is 1410065408, error in precision.
long long int d = a*b; // Note this is also giving error value coz, calcultation was done on two ints which were later 
//converted into long long ie they already lost their data before converting
cout<<c<<" "<<d<<endl;

//Now if you store a value more than its capacity then , what happens is the number line of range of value bacomes a number
//circle eg if min val is 1 and max is 9 , if you add 1 to 9 it will result in 1, it looped back to starting, this is 
//overflow

int p = INT_MAX;
cout<<"An exapmle of overflow "<<p+1<<endl; //An exapmle of overflow

//Long long is way better than double, double although can store more than long long but in exchange it will cost you your precision. warna we can simply use cout<<fixed(no scientific notation)<<setprecision(0){removes decimal}<<variable to give value same form as long long


//A question where the answer came wrong coz of overflow!!
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        long long pdt=1,temp; //⚠️Here, before i used int and got wrong answer, then made it long long
        for (int i = 0; i < n; i++)
        {
            cin>>temp;
            pdt*=temp;
        }
        if(pdt%10==2 || pdt%10 == 3 || pdt%10==5)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    
}

