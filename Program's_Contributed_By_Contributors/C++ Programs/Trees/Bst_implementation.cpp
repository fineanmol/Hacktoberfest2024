#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *le, *rig;
};

class BST
{
    private:

        Node *root, *temp, *temp1;

    public:

        BST(){
            root = NULL;
        }
        Node * getRoot(){
            return root;}
        
        void insert( int key, Node *& temp)
        {
            if ( root == NULL)
            {
                temp=new Node;
                temp->data=key;
                temp->le=temp->rig=NULL;
                root=temp;
                return;
            }

            if (key==temp->data){
                cout << "\nDuplicate value." << endl;
                return;
            }

            if (key>temp->data){
                if (temp->rig==NULL){
                    
                    temp1 = new Node;
                    temp1->data=key;
                    temp->rig=temp1;
                    temp1->le=temp1->rig=NULL;

                    return;
                }
                insert ( key,temp->rig);

                return;
            }

            if (key<temp->data){
                if ( temp->le==NULL){

                    temp1 = new Node;
                    temp1->data=key;
                    temp->le=temp1;
                    temp1->le=temp1->rig=NULL;

                    return;
                }
                insert ( key,temp->le);

                return;
            }
        }

        Node * search( int key, Node *& temp)
        {
            if (root==NULL)
            {
                cout << "\nEmpty" << endl;
                return NULL;
            }

            if (temp->data==key){
                return temp;
            }

            if ( ( temp->rig!=NULL) && (key>temp->data)){
                return search(key,temp->rig);
            }

            if ((temp->le!=NULL)&&(key<temp->data))
            {
                return search( key, temp->le);
            }

            if ( temp->le==NULL&&temp->rig==NULL)
            {
                cout << "\nNot Found." << endl;
                return NULL;
            }
        }

        void print_in( Node *& temp)
        {
            if (root==NULL){
                cout << "\nEmpty." << endl;
                return;
            }
           cout<<temp->data<< "\t";
            if ( temp->le!=NULL)
                print_in( temp->le);

          

            if (temp->rig!=NULL)
                print_in(temp->rig);
        }
        

        Node * succesor(int key)
        {
            temp1=NULL;

            temp=search(key,root);

            if (temp->rig!=NULL){
                temp=temp->rig;

                if (temp->le!=NULL){
                    while (temp->le!=NULL){
                        temp=temp->le;
                    }
                }
                return temp;
            }

            temp=root;

            while (temp->data!=key){

                if ( temp->data>key){
                    temp1 = temp;
                }

                if ((temp->rig!=NULL) && (key>temp->data)){
                    temp=temp->rig;

                    if (temp->data>key){
                        temp1=temp;
                    }
                }

                if ((temp->le!=NULL) && (key<temp->data)){
                    temp=temp->le;

                    if (temp->data>key){
                        temp1=temp;
                    }
                }
            }

            if (temp1 ==NULL){
                return NULL;
            }

            return temp1;
        }

        Node * delete_node( int key, Node * temp, Node * temp1 = NULL) 
        {
            if (temp==NULL)
                return NULL;
            
            if (temp->data==key)
            {

                if ( temp->le==NULL && temp->rig==NULL)
                {
                    if ( temp1->le==temp){
                        temp1->le=NULL;
                        delete temp;
                        return NULL;
                    }
                    if (temp1->rig==temp){
                        temp1->rig=NULL;
                        delete temp;
                        return NULL;
                    }
                }

                if ( temp->le==NULL || temp->rig==NULL)
                {
                    if ( temp1->le==temp)
                    {
                        if (temp->le!=NULL)
                        {
                            temp1->le=temp->le;
                            delete temp;
                            return NULL;
                        }

                        if ( temp->rig!=NULL){
                            temp1->le=temp->rig;
                            delete temp;
                            return NULL;
                        }
                    }
                    if (temp1->rig==temp)
                    {
                        if ( temp->le!=NULL)
                        {
                            temp1->rig=temp->le;
                            delete temp;
                            return NULL;
                        }

                        if ( temp->rig!=NULL){
                            temp1->rig=temp->rig;
                            delete temp;
                            return NULL;
                        }
                    }
                }


                Node * succ = succesor( key);   
                int swap = succ->data;            
                delete_node(succ->data, root);  
                temp->data=swap;               
                return NULL;
            }

            if ( key<temp->data && temp->le!=NULL)
                delete_node( key,temp->le, temp1=temp);

            if ( key>temp->data && temp->rig!= NULL)
                delete_node( key, temp->rig, temp1=temp);
        }

};

int main()
{
    BST tree;

    Node * r = tree.getRoot(); 

    tree.insert(10, r);
    tree.insert(8,r);
    tree.insert(6,r);
    tree.insert(9,r);
    tree.insert(15,r);
    tree.insert(14,r);
    tree.insert(20,r);

    cout << "\nBefore Deletion : " << endl;
    tree.print_in(r);
    tree.delete_node(9,r);
    tree.delete_node(14,r);


    cout << "\nAfter Deletion : " << endl;

    tree.print_in(r);

}

