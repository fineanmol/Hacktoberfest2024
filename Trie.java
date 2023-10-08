class Trie{
    Trie child[];
    boolean isEnd;
    Trie(){
        child = new Trie[26];
        isEnd = false;
    }
    public void insert(String word){
        Trie curr = this;
        for(char c : word.toCharArray()){
            int idx = c-'a';
            if(curr.child[idx] == null){
                curr.child[idx] = new Trie();
            }
            curr = curr.child[idx];
        }
        curr.isEnd = true;
    }
    public boolean search(String word){
        Trie curr = this;
        for(char c : word.toCharArray()){
            int idx = c-'a';
            if(curr.child[idx] == null){
                return false;
            }
            curr = curr.child[idx];
        }
        return curr.isEnd;
    }
    public boolean startsWith(String prefix){
        Trie curr = this;
        for(char c : prefix.toCharArray()){
            int idx = c-'a';
            if(curr.child[idx] == null){
                return false;
            }
            curr = curr.child[idx];
        }
        return true;
    }
    
    public static void main(String[] args) {
        Trie root = new Trie();

        String [] sen = {"my", "name", "is", "kanai"};
        for(String s: sen){
            root.insert(s);
        }

        System.out.println(root.search("kanai"));
        System.out.println(root.search("kan"));
        System.out.println(root.startsWith("naruto"));

    }
}