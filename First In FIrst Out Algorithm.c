// C program to demonstrate
// working of FIFO
// using Queue interface in C
 
#include<bits/stdc++.h>
using namespace std;
 
// print the elements of queue
void print_queue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
 
// Driver code
int main()
{
    queue<int> q ;
 
    // Adds elements {0, 1, 2, 3, 4} to queue
    for (int i = 0; i < 5; i++)
        q.push(i);
 
    // Display contents of the queue.
    cout << "Elements of queue-";
         
    print_queue(q);
 
    // To remove the head of queue.
    // In this the oldest element '0' will be removed
    int removedele = q.front();
    q.pop();
    cout << "removed element-" << removedele << endl;
 
    print_queue(q);
 
    // To view the head of queue
    int head = q.front();
    cout << "head of queue-" << head << endl;
 
    // Rest all methods of collection interface,
    // Like size and contains can be used with this
    // implementation.
    int size = q.size();
    cout << "Size of queue-" << size;
         
    return 0;
}
 
