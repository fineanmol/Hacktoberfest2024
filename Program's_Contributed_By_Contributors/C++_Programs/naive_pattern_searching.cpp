#include <bits/stdc++.h>
using namespace std;

void patternSearch(char* pattern, char* string)
{
	int m = strlen(pattern);
	int n = strlen(string);

	for (int i = 0; i <= n - m; i++) {
		int j;

		for (j = 0; j < m; j++)
			if (string[i + j] != pattern[j])
				break;
        if (j == m)
        //returning the index where "AN" occurs in "I AM SHUBHANGI. AN AVID READER WHO LIKES TO LISTEN TO MUSIC."
			cout << "'AN' occurs in 'I AM SHUBHANGI. AN AVID READER WHO LIKES TO LISTEN TO MUSIC.' at :  "
				 << i << endl;
	}
}

int main()
{
	char string[] = "I AM SHUBHANGI. AN AVID READER WHO LIKES TO LISTEN TO MUSIC.";
	char pattern[] = "AN";
	patternSearch(pattern, string);
	return 0;
}
