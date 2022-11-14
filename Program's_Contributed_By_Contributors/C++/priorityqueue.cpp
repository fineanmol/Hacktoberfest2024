#include <iostream>
#include <queue>

// priorityqueue is - first ielement must be greater//
// default pq is max heap
using namespace std;
int main()
{
    // maxheap
    priority_queue<int> maxi;
    // min-heap
    priority_queue < int, vector<int>, greater<int> > mini;

    maxi.push(1);

    maxi.push(3);

    maxi.push(9);
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;
}