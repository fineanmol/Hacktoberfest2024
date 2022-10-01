/*
The question of of finding the next greaeter element is using stack to work, what actually happens is we traverse the array
we store the "Indexes" first element of the array into the stack, and then in further iteraton, we just see that if the 
element in that index is greater than the elements in the indexes stored in the stack , if so then we pop the indexes from
the stack and store the current index. Simultaneously we're assigning the current index to the indexes we're popping out.
The final array actually contains the indexes of the NGE, wrt the orignal array
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> v)
{
    stack<int> st;
    vector<int> nge(v.size()); //⚠️⚠️⚠️The size of vector is declared inside normal brackets!
    for (int i = 0; i < v.size(); ++i)
    {
        while(!st.empty() && v[i]>v[st.top()]) //If the element at current index is more than the element whose index is there
        //in stack
        {
            nge[st.top()] = i;  //Stoer the index of current element in the places of the elements whose indexes are there
            st.pop(); //Remove those indexes after assingning their NGL
        }
        st.push(i); //Insert the greatest elements index in the stack
    }
    while (!st.empty()) //Assaigning the elements whose NGE wasn't present an index of -1
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        vector<int> nge = NGE(v);
        for (int i = 0; i < n; ++i)
        {
            cout << v[i] << " " << (nge[i]==-1?-1:v[nge[i]])<< endl;
        }
    }
}