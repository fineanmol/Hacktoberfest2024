#include <iostream>
#define N 5
using namespace std; 

//STACK IMPLEMENTATION USING ARRAYS (STATIC IMPLEMENTATION)

int stack[N]; 
int top = -1; //top of the stack 



//PUSH (to insert an element into the stack)

void Push(){

    int x; 
    cout << "enter the number that u want to push" << endl; 
    cin >> x; 

    if(top == N-1){
        cout << "stack is full that means overflow" <<endl; 

    } else {
        
        top ++; 
        stack[top] = x; 
        cout << "current stack: " << stack[top] << endl; 
        
    }


}



//POP (to delete an element from the stack)

void Pop(){
    if(top == -1){
        cout << "stack is empty or it is underflow" << endl; 

    }
    else {
        cout << "Now, current stack is: " <<endl; 
        int item = stack[top];  // to store your deleted value
        top --;
        cout << "deleted item: " <<item << endl;  
        cout << "current stack: " << stack[top] <<endl;
    }


}



//PEEK  (to display the topmost element of the stack)

void Peek(){
    if(top == -1){
        cout << "stack is empty or it is underflow" << endl; 
    }

    else {
        cout << stack[top] << endl; 
  
    }
}



//DISPLAY  (to display all the elements of the stack)

void display(){
    for(int i = top; i>=0; i--){
        cout << "here is ur stack: " << stack[i] << endl;
    }
}



//SWITCH STATEMENTS in order to execute our code. 

int main(){

    int number; 

    cout << "enter number" <<endl; 
    cin >> number; 

    switch(number){

        case 1: Push(); 
        break; 

        case 2: 
        { 
            int num; 
            cout << "enter another number" <<endl; 
            cin >> num; 

            switch(num){
                case 1: Push();
                Pop(); 
                break;

                case 2: Pop(); 
                break; 

                default: 
                break; 

            }
            
        }
        break;
        
        case 3: Peek(); 
        break;

        case 4: display();
        break; 

        default: 
        cout << "wrong no. pls enter valid no. " <<endl; 
        break; 


    }

    return 0; 

   }
