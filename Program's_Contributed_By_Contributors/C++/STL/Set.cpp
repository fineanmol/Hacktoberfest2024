#include <iostream>
#include <set>
using namespace std;

// element return in seted order and can not modifyed
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(0);
    s.insert(23);
    s.insert(0);

    // printing set eassily in sorted form
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout<<endl;
    // delect element
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for (auto i : s)
    {
        cout << i << " ";
    }
}