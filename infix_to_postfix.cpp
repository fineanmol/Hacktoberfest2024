#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
bool digitCheck(char c)
{
	return c >= '0' && c <= '9';
}
bool alphaCheck(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
string infixToPostfix(string str)
{
	string s = "";
	stack <char> st;
	for (int i = 0; str[i]; i++)
	{
		if (alphaCheck(str[i]) || digitCheck(str[i]))
		{
			s.push_back(str[i]);
			continue;
		}
		else if (str[i] == '(')
			st.push('(');
		else if (str[i] == ')')
		{
			while (st.top() != '(')
			{
				s.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
			{
				if (str[i] == '^' && st.top() == '^')
					break;
				s.push_back(st.top());
				st.pop();
			}
			st.push(str[i]);
		}
	}
	while (!st.empty())
	{
		s.push_back(st.top());
		st.pop();
	}
	return s;
}

string infixToPrefix(string s)
{
	reverse(s.begin(), s.end());
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == ')')
			s[i] = '(';
		else if (s[i] == '(')
			s[i] = ')';
	}
	string res = infixToPostfix(s);
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	string s = "(a-b/c)*(a/k-l)";
	cout << infixToPostfix(s) << endl;;
	cout << infixToPrefix(s);
}