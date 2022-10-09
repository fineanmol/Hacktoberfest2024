#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9;
#define inf2 2e18;



struct custom_hash {
   static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
   size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};



struct TrieNode{ TrieNode* child[26]; bool isEnd;
    TrieNode(){ isEnd = false; for(int i = 0; i<26; i++){ child[i] = NULL; } }
};
struct TrieNode* rootTrie;
void addTrie(string& s){ TrieNode* curr = rootTrie; for(int i = 0; i<s.length(); i++){ int n = s[i] - 'a';if(curr->child[n] == NULL){curr->child[n] = new TrieNode();} curr = curr->child[n]; } curr->isEnd = true; }
bool searchTrie(string& s){TrieNode* curr = rootTrie;for(int i = 0; i<s.length(); i++){int n = s[i] - 'a';if(!curr->child[n]) return false;curr = curr->child[n];}return curr->isEnd;}
bool startsWithTrie(string s) {int n = s.length();TrieNode* curr = rootTrie;for(int i  =0 ; i<n; i++){int k = s[i] - 'a';if(curr->child[k] == NULL) return false;curr = curr->child[k];}return true;}



int main(){
//Jai Shree Ram
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct TrieNode *root = getNode();

    for (int i = 0; i < n; i++) insert(root, keys[i]);
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    cout<<"the"<<" --- "<<output[search(root, "the")]<<endl;
    cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
    cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
    cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;
    return 0;
}