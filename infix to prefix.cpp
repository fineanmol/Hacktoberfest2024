#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char s)
{
	if (s == '+' || s == '-')
		return 1;
	else if (s == '*' || s == '/')
		return 2;
	return 0;
}
string infixToPrefix(string s)
{
	string ans;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == ')')
			s[i] == '(' ? s[i] = ')' : s[i] = '(';
	}
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			ans += s[i];
		else if (s[i] == '(')
			st.push('(');
		else if (s[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && prec(st.top()) > prec(s[i]))
			{
				ans += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main()
{
	cout << infixToPrefix("(a-b/c)*(a/k-l)");
	return 0;
}
