#include <bits/stdc++.h>
using namespace std;
#define For(j, i, f) for (int j = i; j <= f; j++)
#define lli long long int
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define pb push_back
#define foreach(x, arr) for (auto x : arr)
#define all(x) (x).begin(), (x).end()
#define PQi priority_queue<int, vector<int>>
#define inputArr(arr, n) For(i, 0, n - 1) cin >> arr[i];
#define coutline(arr)                    \
    string outstr = "";                  \
    for (int i = 0; i < arr.size(); i++) \
        outstr += arr[i];                \
    cout << outstr;

#define ALPHABET_SIZE 26

#define indexOf(c) ((int)c - (int)'a')


//  VERY NICE PROBLEM. FINDING SUBSTRINGS USING TRIE.

// A trie is create for a string. Substrings starting from each position of the string
// is inserted into the trie. Now we just need to count the substrings from it only.
// Very nice logic.


class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    TrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Trie
{
private:
    TrieNode *node;

public:
    Trie()
    {
        node = new TrieNode();
    }

    void insert(string str)
    {
        int n = str.length();
        TrieNode *curr = node;
        for (int i = 0; i < n; i++)
        {
            int index = indexOf(str[i]);
            if (!curr->children[index])
            {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
        cout << str << " inserted\n";
    }

    void createSubstringTrie(string &s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            insert(s.substr(i, n - i));
        }
    }

    int countSubstringsUtil(TrieNode *root)
    {
        if (!root)
            return 0;
        int count = 1;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            count += countSubstringsUtil(root->children[i]);
        }
        cout << "count is " << count << endl;
        return count;
    }
    int countSubstrings()
    {
        return countSubstringsUtil(node);
    }
};

int countDistinctSubstrings(string s)
{
    cout << "started\n";
    Trie *trie = new Trie();
    trie->createSubstringTrie(s);
    return trie->countSubstrings();
}

int main()
{
    cout << countDistinctSubstrings("hello") << endl;
    return 0;
}