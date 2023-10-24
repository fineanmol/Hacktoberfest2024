#include <iostream>
#include <queue>

using namespace std;

//Queue: It is data structure which follow FIFO method to store data
// FIFO: First In First Out
// LILO: Last In Last Out
// Application: Whenever we need to things to be happen in order they are called eg- printer printing pages

void print(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " " ;
        q.pop();
    }
    cout << endl;
}
int main(){

    queue<int> q;

    // adding elements in queue
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Size of the queue: " << q.size() << endl;
    cout << "First element of the queue: " << q.front() << endl;
    cout << "Last element of the queue: " << q.back() <<  endl;

    print(q);


    system("pause>0");
}