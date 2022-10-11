// https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1
/* Given a string without spaces, the task is to remove duplicates from it.*/
//User function template for C++
class Solution {
public:

	string removeDups(string S)
	{
		if (S == " " || S == "")
			return S;
		unordered_map<char, int>mp;
		int len = S.size();
		for (int i = 0; i < len; i++)
		{
			mp[S[i]]++;
		}
		string result = "";
		for (int i = 0; i < len; i++)
		{
			if (mp[S[i]] != -1)
			{
				result += S[i];
				mp[S[i]] = -1;
			}
		}
		return result;
	}
};