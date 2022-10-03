/* C++ program to implement Hash Table using Template Class  */

#include <iostream>
#include <stdlib.h>

using namespace std;

template<class E, class K>
class HashTable {
        public:
                HashTable(int divisor = 11);
                ~HashTable() {delete [] ht;
                        delete [] empty;}
                        int Search(const K& k, E& e) const;
                        HashTable<E,K>& Insert(const E& e);
                        void Output();// output the hash table
                        void del(E e);
        private:
                        int hSearch(const K& k) const;
                        int D; // hash function divisor
                        E *ht; // hash table array
                        int *empty; // 1D array
};
        template<class E, class K>
HashTable<E,K>::HashTable(int divisor)
{// Constructor.
        D = divisor;
        ht = new E [D];
        empty = new int [D];

        for (int i = 0; i < D; i++)
                empty[i] = 1;
}
template<class E, class K>
int HashTable<E,K>::hSearch(const K& k) const
{
        int i = k % D;
        int j = i;
        do {
                if (empty[j] || ht[j] == k) return j;
                j = (j + 1) % D;  // next bucket
        } while (j != i); // returned to home?
        return j;  // table full
}
        template<class E, class K>
void HashTable<E,K>::del(E e)
{
        int b=hSearch(e);
        if( !empty[b] && ht[b]==e)
        {
                ht[b]=0;
                empty[b]=1;
        }
        else
                cout<<"\nelement not found";

}
template<class E, class K>
int HashTable<E,K>::Search(const K& k, E& e) const
{
        int b = hSearch(k);
        if (empty[b] || ht[b] != k) return 0;
        e = ht[b];
        return 1;
}
        template<class E, class K>
HashTable<E,K>& HashTable<E,K>::Insert(const E& e)
{// Hash table insert.
        K k = e; // extract key
        int b = hSearch(k);
        if (empty[b]) {empty[b] = 0;
                ht[b] = e;
                return *this;

        }
        if (ht[b] == k) { cout<<"\nbad input"; return *this; } // duplicate
        cout<<"\nNo memory";// table full
        return *this;
}

        template<class E, class K>
void HashTable<E,K>::Output()
{
        cout<<endl;
        for (int i = 0; i< D; i++) {
                if (empty[i]) cout << "0 ";
                else cout << ht[i]<<" ";}
        cout<<endl;
}
class element {
        public:
        operator long() const {return key;}
        private:
        int data;
        long key;
};

int main()
{
        HashTable<int , int > h(11);
        int e;
        e = 80;
        h.Insert(e);
        e = 40;
        h.Insert(e);
        e = 65;
        h.Insert(e);
        cout<<"\nAfter inserting 80,40,65:";
        h.Output();
        cout<<endl;
        h.del(40);
        cout<<"\nAfter deleting 40:";
        h.Output();
        cout<<endl;
        e = 58;
        h.Insert(e);
        e = 24;
        h.Insert(e);
        cout<<"\nafter appending 58, 24:";
        h.Output();
        cout<<"\nTrying to delete element 25:";
        h.del(25);
        h.Output();
        e = 2;
        h.Insert(e);
        e = 13;
        h.Insert(e);
        e = 46;
        h.Insert(e);
        e = 16;
        h.Insert(e);
        e = 7;
        h.Insert(e);
        e = 21;
        h.Insert(e);
        h.Insert(10);
        cout <<"After inserting more values:" << endl;
        h.Output();
        e = 99;
        cout<<"\ntrying to insert 99:";
        h.Insert(e);
        h.Output();
        return 0;
}