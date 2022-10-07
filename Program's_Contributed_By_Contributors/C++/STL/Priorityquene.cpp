#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //max heap
    priority_queue<int> max;
    //min heap 
    priority_queue<int ,vector<int> ,greater<int>> min;

    max.push(1);
    max.push(2);
    max.push(3);
    int b=max.size();
    for(int i=0;i<b;i++){
        cout<<max.top()<<" ";
        max.pop();
        
    }

    //in case min heap it give min value
}