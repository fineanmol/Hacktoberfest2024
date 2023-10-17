/* Name:Sarvesh Pramod Biwalkar
   Topic: Doubly Linked List for Complement.
   
*/

#include <iostream>
using namespace std;

class DLL{
	bool num;
	DLL *next;
	DLL *prev;
	public:
		static DLL *start , *end;  //pointer
		DLL(){
			cout<<"Enter a binary bit of number: "<<endl;
			cin>>num;
			next=prev=NULL;
			if(start==NULL)   //the list is empty
			{
				start=end=this;    //this is the current node called by constructor
			}
			else    //list is not empty
			{
				end -> next = this;
				this -> prev = end;
				end = this;	
			}
	    }
		void Display(){
		   	DLL *ptr = start;
		   	cout<<"NULL<-";
			while(ptr!=NULL)
			{
				cout<<ptr->num;	
				ptr = ptr -> next;
			}		
			cout<<"NULL"<<endl;
		}
		void onescomplement(){
			DLL *ptr = start;
			cout<<"Ones complement of binary number is: "<<endl;
			while(ptr!= NULL)
			{
				cout<<!(ptr -> num);   //! sign indicates complement of the number
				ptr = ptr -> next;
			}
		}
		void twoscomplement(){
			DLL *ptr = end;
			bool twoscomp[15];
			int i=-1;
			while(ptr!=NULL && ptr -> num == 0)
			{
				twoscomp[i]=0;
				ptr = ptr -> prev;
			}
			twoscomp[++i]=1;     //pre increament (increamentation before execution)
			while(ptr!=NULL)
			{
				twoscomp[++i]=!(ptr -> num);
				ptr = ptr -> prev;
			}
			cout<<"Twos complement of binary number is : "<<endl;
			while(i >= 0 )
			{
				cout<<twoscomp[i--];     ////post increament (increamentation after execution)
			}
		}
};
DLL *DLL::start = NULL;
DLL *DLL::end = NULL;

int main (){
	DLL *obj;
	int ch;
	do{
		cout<<endl<<".....MENU..... "<<endl;
		cout<<" 1. Add bit into binary number"<<endl;
		cout<<" 2. Display"<<endl;
		cout<<" 3. One's complement "<<endl;
		cout<<" 4. Two's complement "<<endl;	
		cout<<" 5. Exit"<<endl;
		cout<<" Enter your choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				obj = new DLL();
				break;
			case 2:
				obj -> Display();
				break;
			case 3:
				obj -> onescomplement();
				break;
			case 4:
				obj -> twoscomplement();
				break;
			case 5:
				exit(0);
		}
	}
	while(ch!=5);
	return 0;
}
	


