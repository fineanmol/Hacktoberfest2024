
#include<iostream>
#define size 1000
using namespace std;
class stack{
    private :
    int top;
    int arr[size];

    public:

    stack(){
        top = -1;
    }

    bool push(int x){
        if(top>=size-1){
            cout<<"stack is full"<<endl;
            return false; 
        }
        arr[++top] = x;
        return true;
    }

    int pop(){
        if(top<1){
            cout<<"stack is underflow";
            return 0;
        }
        return arr[top--];
    }

    int peek(){
        if (top<1){
            cout<<"stack is underflow";
            return 0;
        }
        return arr[top];   
    }

    bool isempty(){
        return (top<1);
    }

    void print(){
        if(top<1){
            cout<<"stack is empty"<<endl;
        }

        for(int i = top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    stack s;
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        s.push(x);
    }
    cout<<s.isempty()<<endl;
    cout<<"Element of the stack are :"<<endl;
    s.print();
}
