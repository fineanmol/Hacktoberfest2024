#include<bits/stdc++.h>
using namespace std;


class TrieNode{
    public: 
          unordered_map<char,TrieNode*> umap;
          bool endofword = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
         root  =  new TrieNode();     
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int i=0;
        TrieNode* new_node;
        while(i<word.length()){
            auto itr = (node->umap).find(word[i]);
            if(itr == (node->umap).end()){
                new_node = new TrieNode();
                if(i==word.length()-1){
                    new_node->endofword = true;
                }
                (node->umap).insert({word[i],new_node});
                node = new_node;
                
            }else{
                node = itr->second;
                 if(i==word.length()-1){
                     node->endofword = true;
                }
            }
            i++;
        }        
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int i = 0;
        while(i<word.length()){
            auto itr = (node->umap).find(word[i]);
            if(itr != (node->umap).end()){
                node = itr->second;
                i++;
            }else{
                return false;
            }
        }
        
        if(node->endofword){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
         TrieNode* node = root;
        int i = 0;
        while(i<prefix.length()){
            auto itr = (node->umap).find(prefix[i]);
            if(itr != (node->umap).end()){
                node = itr->second;
                i++;
            }else{
                return false;
            }
        }
        
        return true;
        
    }
};

int main(){
	
   vector<string> arr =  {"apple","app","aps","lmn"};
   vector<string> prefixs = {"app","lmn","ln","al"};
   vector<string> word_search = {"apple","apps"};
   
   Trie* obj = new Trie();
   for(int i=0;i<arr.size();i++)
        obj->insert(arr[i]);
   
   for(int i=0;i<word_search.size();i++){
        bool param_2 = obj->search(word_search[i]);
        cout<<word_search[i]<<" : "<<param_2<<endl;
   }
   
   for(int i=0;i<prefixs.size();i++){
        bool param_3 = obj->startsWith(prefixs[i]);
        cout<<prefixs[i]<<" : "<<param_3<<endl;
   }
   
   return 0;
	
}
