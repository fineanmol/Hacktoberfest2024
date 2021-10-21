/*
    
    Program Description:  A C++ program to create a class called LIST (Linked List) with member functions to:
    
                    	i. Insert an element at any position.
    
                    	ii. To display the list.
    
    Author: Nilay Gupta
                   

    
    INPUT AND OUTPUT:
    
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        1
        
        -----------------------------------
        
        Enter the element that you want to insert:
        10
        
        Enter the position at which you want to insert the element:
        1
        
        ELEMENT INSERTION WAS SUCCESSFUL
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        1
        
        -----------------------------------
        
        Enter the element that you want to insert:
        20
        
        Enter the position at which you want to insert the element:
        2
        
        ELEMENT INSERTION WAS SUCCESSFUL
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        1
        
        -----------------------------------
        
        Enter the element that you want to insert:
        30
        
        Enter the position at which you want to insert the element:
        1
        
        ELEMENT INSERTION WAS SUCCESSFUL
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        1
        
        -----------------------------------
        
        Enter the element that you want to insert:
        40
        
        Enter the position at which you want to insert the element:
        2
        
        ELEMENT INSERTION WAS SUCCESSFUL
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        1
        
        -----------------------------------
        
        Enter the element that you want to insert:
        50
        
        Enter the position at which you want to insert the element:
        3
        
        ELEMENT INSERTION WAS SUCCESSFUL
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        2
        
        -----------------------------------
        
        The Linked List is:
        
        Data 1 : 30
        
        Data 2 : 40
        
        Data 3 : 50
        
        Data 4 : 10
        
        Data 5 : 20
        
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        5
        
        -----------------------------------
        
        Invalid choice, please try again!
        
        ---------------MENU---------------
        
        Press 1 to insert an element
        
        Press 2 to display the list
        
        Press 3 to exit
        
        Enter your choice (1 - 3):
        3
        
        -----------------------------------
        
        Thank you for using the program!
    
    
    Algorithm:
    
        Step 0: Start
       
        Step 1: Declare the header files
       
        Step 2: Create a struct Node which will store the data and the link to the
                insertress
       
        Step 3: Create a class and declare all the member functions and data members
       
            Step 3.1: insertNode()
                Step 3.1.1: Traverse the Linked List upto position-1 nodes.
                Step 3.1.2: Once all the position-1 nodes are traversed, allocate
                            memory and the given data to the new node.
                Step 3.1.3: Point the next pointer of the new node to the next of
                            current node.
                Step 3.1.4: Point the next pointer of current node to the new node.
    
        Step 4: Create a main function which will have the menu for the user and
                also the driver code for the program
       
        Step 5: Stop

*/

//declaration of header files
#include <iostream>
using namespace std;

// A Linked List Node
struct Node
{    
   
    int data;
    struct Node* next;
   
};
 
class LIST
{
   
    public:
   
        // Size of Linked List
        int size = 0;
 
        // function to create and return a Node
        Node* getNode(int data)
        {
   
            // allocating space
            Node* newNode = new Node();
 
            // inserting the required data
            newNode->data = data;
            newNode->next = NULL;
   
            return newNode;
   
        }
 
        // function to insert a Node at required position
        void insertNode(Node** current, int pos, int data)
        {
   
            // This condition to check whether the position given is valid or not.
            if (pos < 1 || pos > size + 1)
            {
           
                cout << "\nInvalid position!" << endl;
   
            }
   
            else
            {
       
                // Keep looping until the pos is zero
                while (pos--)
                {
 
                    if (pos == 0)
                    {
 
                        // inserting Node at required position
                        Node* temp = getNode(data);
 
                        // Making the new Node to point to the old Node at the same position
                       temp->next = *current;
 
                        // Changing the pointer of the Node previous to the old Node to point to the new Node
                        *current = temp;
               
                    }
           
                    else
                    {
                 
                        // Assign double pointer variable to point to the pointer pointing to the insertress of next Node  
                        current = &(*current)->next;
           
                    }
           
                }
       
                size++;
       
                cout<<"\nELEMENT INSERTION WAS SUCCESSFUL"<<endl;
       
            }
   
        }
 
        // This function prints contents of the Linked List  
        void display(struct Node* head)
        {
   
                int e=0;
   
                while (head != NULL)
                {
       
                    cout <<"\nData "<<++e<<" : "<< head->data<<endl;
                    head = head->next;
       
                }
   
                cout << endl;
   
            }
};
 
// Driver Code
int main()
{
   
    LIST obj;
   
    // making the link of the first node point to NULL
    Node* head = NULL;
 
    obj.size = 0;
   
    int ch;
   
    int num, pos;
   
    while(1)
    {
       
        cout<<"\n---------------MENU---------------"<<endl;
        cout<<"\nPress 1 to insert an element"<<endl;
        cout<<"\nPress 2 to display the list"<<endl;
        cout<<"\nPress 3 to exit"<<endl;
       
        cout<<"\nEnter your choice (1 - 3):"<<endl;
        cin>>ch;
       
        cout<<"\n-----------------------------------"<<endl;
       
        switch(ch)
        {
           
            case 1: cout<<"\nEnter the element that you want to insert:"<<endl;
                    cin>>num;
                    cout<<"\nEnter the position at which you want to insert the element:"<<endl;
                    cin>>pos;
                    obj.insertNode(&head, pos, num);
                    break;
           
            case 2: cout<<"\nThe Linked List is:"<<endl;
                    obj.display(head);
                    break;
                   
            case 3: cout<<"\nThank you for using the program!"<<endl;
                    exit(0);
                   
            default: cout<<"\nInvalid choice, please try again!"<<endl;
           
        }
       
    }
   
  return 0;
 
}