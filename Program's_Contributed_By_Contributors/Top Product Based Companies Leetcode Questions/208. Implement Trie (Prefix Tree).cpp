// it is the trieNode class designed some functions according to the oops concepts which makes the solution interview friendly
class TrieNode{
public:
    TrieNode* next[26];
    bool isCompleted; 
    
    TrieNode(){
        for(auto &x: next) x=nullptr;
        isCompleted = false;
    }
    
    // if the character is present in the reference array of the current node
    bool isPresent(char a,TrieNode* node) {
        return node->next[a-'a'];
    }
    
    // set the reference array value corresponding to the current character and points to the newnode
    void setValue(TrieNode* node, char a, TrieNode* newnode, bool isLast){
        node->next[a-'a']= newnode;
        // if the we reach at the end of the word make the isLast True which signifies we reach at the word end
        if(isLast) newnode->isCompleted = true; 
    }
    
    // if we reach the end of the word or not
    void atLast(TrieNode* node){
        node->isCompleted = true;
    }
    
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        // insert the word in the trie
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->isPresent(word[i],curr)){                    
                (i==word.size()-1)?curr->setValue(curr,word[i], new TrieNode(), true):
                curr->setValue(curr, word[i], new TrieNode(), false);
            }
            curr = curr->next[word[i]-'a'];
        }
        curr->atLast(curr);
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->isPresent(word[i],curr)){
                return false;
            }
            curr= curr->next[word[i]-'a'];
        }
        return curr->isCompleted;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->isPresent(prefix[i],curr)){
                return false;
            }
            curr= curr->next[prefix[i]-'a'];
        }
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */