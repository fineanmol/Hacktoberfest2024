#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	int data;
	Node *nextNode;
	
};
class stack{
	public:
		Node *top;
	stack(){
		this->top=NULL;
	}
	void push(int value){
		Node *temp = new Node;
		temp->data = value;
		temp->nextNode = NULL;
		if(top = NULL){
			top = temp;
			temp->nextNode = NULL;
		}
		else{
			temp->nextNode = top;
			top=temp;
		}
	}
	int pop(){
		if(top !=NULL){
			Node *temp = top;
			top = top->nextNode;
			delete temp;
		}
		else{
			cout<< "Stack does not exists: "<<endl;
		}
	}
};
int main(){
	stack object;
	char c[20], a, b, d;
	cout<< "Enter your expression!: "<<endl;
	for(int i = 0 ; i < 4 ; i++){
	cin>>c[i];
	}
for (int i = 0; i < 4; i++){
	
	if((c[i]='(') || (c[i]='{' )|| (c[i]='[')){
		
        object.push(c[i]);
	}
	else {
	    switch(c[i])
	    {
		case ')':
            a = object.pop(); 
		    if ((a == '{') || (a == '[')){
		    	
		     	cout<<"invalid expr!!";
               
			 }   
			 break;
		case '}':
            b = object.pop();
			if ((b == '[') || (b == '(')){
				
			     cout<<"invalid expr!!";
                
			 }   
			 break;
		case ']':
            d = object.pop();
			 if ((d == '{') || (d == '('))
			 {
			    cout<<"invalid expr!!";
                
			 }   
			 break;
	    }
}
    }
    if (object.top == NULL)
    {
	cout<<"balanced expr!!";
    }
    else
    {
	cout<<"string is not Balanced!!";
    }
    return 0;

}	
	
