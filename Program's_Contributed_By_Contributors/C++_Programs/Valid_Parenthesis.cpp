/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid or not .

An input string is valid if:

 a) Open brackets must be closed by the same type of brackets.
 b) Open brackets must be closed in the correct order.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define pf push_front

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Declaring a string variable named 's':
    string s;
    //Declaring  a bool variable to store the value and initializing it as true
    bool result = true;
    cout << "Enter a string containing";
    cout << "("
         << ")"
         << "{"
         << "}"
         << "["
         << "]" << endl;

    //Taking the string of brackets as input
    cin >> s;

    //Declaring a stack of type char, since each of the bracket as individual are treated as characters:
    stack<char> st;

    //Traversing through the length of the string:
    for (int i = 0; i < s.length(); i++)
    {
        //checking the the character at the ith index is '(' / '{' / '['
        //in either case we need to push it in the stack

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

        //checking the condition when the character is neither of the opening bracket

        else
        {

            if (s[i] == ')')
            {
                //checking if the stack is empty or the top of the stack is not the corresponding opening bracket of the closing bracket

                if (st.empty() || st.top() != '(')
                    //In that case the string is invalid.
                    result = false;
                else
                    //If the top of the stack matches with the corresponding opening bracket, then
                    //we're supposed to pop it out of the stack since it is a valid pair
                    st.pop();
            }
            else if (s[i] == '}')
            {
                //checking if the stack is empty or the top of the stack is not the corresponding opening bracket of the closing bracket

                if (st.empty() || st.top() != '{')
                    //In that case the string is invalid.
                    result = false;
                else
                    //If the top of the stack matches with the corresponding opening bracket, then
                    //we're supposed to pop it out of the stack since it is a valid pair
                    st.pop();
            }
            else if (s[i] == ']')
            {
                //checking if the stack is empty or the top of the stack is not the corresponding opening bracket of the closing bracket

                if (st.empty() || st.top() != '[')
                    //In that case the string is invalid.
                    result = false;
                else
                    //If the top of the stack matches with the corresponding opening bracket, then
                    //we're supposed to pop it out of the stack since it is a valid pair
                    st.pop();
            }
        }
    }

    //For the condition where the string contains only opening brackets, the value of result would have been true
    //which would have given us a wrong answer.

    //Checking if the value of result is true and the stack is not empty in that case the string is invalid

    if (result && (!st.empty()))
        result = false;

    if (result)
        //if value of result is true, it's a valid string
        cout << "Valid String" << endl;

    else
        //else it's an invalid string
        cout << "Invalid String" << endl;
}

/*Time complexity of this program would be : O(n), where n is the length of the string

EXPLANATION:
We traversed through the length of the string only once, at the cost of O(n),
the cost of pushing element into the stack and popping them is O(1)

Hence, the overall time complexity of this code is O(n)!



*/
