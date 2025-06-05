#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626
#define ll long long
#define lli long long int
#define fo(i,a,n) for(int i=a;i<n;i++)
#define pr(i,arr) for(auto i:arr)

typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef map<int,int> mi;

void file_i_p()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    return a%b==0 ? b : _gcd(b,a%b);
}

struct Node{
    int data;
    Node* next;
};

Node *head = NULL;

void insertAtHead(int a)
{
    Node *n = new Node();
    n->data = a;
    n->next = NULL;

    if(head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        n->next = head;
        head = n;
        return;
    }

}

void deleteAtHead()
{
    head = head->next;
}

void insertAtLast(int a)
{
    Node* n = new Node();
    n->data = a;
    n->next = NULL;
    Node *temp = head;
    if(head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        return;
    }
}

void deleteAtLast()
{
    Node *t = head;
    if(head == NULL)
    {
        return;
    }
    else
    {
        while(t->next->next!=NULL)
        {
            t = t->next;
        }
        t->next = t->next->next;
    }
    
}

void reverse()
{
    Node *t = NULL;
    Node *k = NULL;
    Node *temp = head;
    while(temp!=NULL)
    {
        t = temp->next;
        temp->next = k;
        k = temp;
        temp = t;
    }
    head = k;
}

void print(Node *t)
{
    if(t == NULL)
    {
        return;
    }
    cout<<t->data<<" ";
    print(t->next);
}

void printRev(Node *t)
{
    if(t == NULL)
    {
        return;
    }
    printRev(t->next);
    cout<<t->data<<" ";
}

void solve()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        insertAtLast(a);
    }

    print(head);
    cout<<endl;
    printRev(head);

}

int main() {
    
    file_i_p();

    solve();

    return 0;
}
