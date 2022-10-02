#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{

    public:
    class node{
      public:
        int key,val;
        node* next,*prev;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int cap;
    map<int,node*> m;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* newnode){
        node* temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    
    void deletenode(node *delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int _key) {
        if(m.find(_key)!=m.end()){
            auto res=m[_key];
            int ans=res->val;
            m.erase(_key);
            deletenode(res);
            addnode(res);
            m[_key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void set(int _key, int _value) {
        if(m.find(_key)!=m.end()){
            auto temp=m[_key];
            m.erase(_key);
            deletenode(temp);
        }
        if(cap==m.size()){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(_key,_value));
        m[_key]=head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
