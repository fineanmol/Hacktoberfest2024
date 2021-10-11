import java.util.LinkedList;

public class HashTable {
    int SIZE = 997; // typically a large enough prime number
    LinkedList<HashNode>[] harr;

    HashTable() {
        harr = new LinkedList[SIZE];
        for (int i=0; i<SIZE; i++)
            harr[i] = new LinkedList<HashNode>();
    }

    public int hash(int x) {
        return (x*x*x + 3*x*x + 1) % SIZE;
    }

    // Add a key-value pair to the hash table
    public void put(int k, int v) {
        int index = hash(k);
        HashNode hn = new HashNode(k,v);
        harr[index].add(hn);
    }

    // Check if the hashtable contains key k
    public boolean contains(int k) {
        LinkedList<HashNode> llhn = harr[hash(k)];
        if ( llhn != null ) {
            for (int i=0; i<llhn.size(); i++) {
                if (llhn.get(i).key == k)
                    return true;
            }
        }
        return false;
    }

    // Retrieve a value from hashtable based on a key
    public int get(int k) {
        LinkedList<HashNode> llhn = harr[hash(k)];
        if ( llhn != null ) {
            for (int i=0; i<llhn.size(); i++) {
                if (llhn.get(i).key == k)
                    return llhn.get(i).value;
            }
        }
        return Integer.MIN_VALUE;      
    }

    // Remove a key-value pair from hashtable given a key
    public void remove(int k) {
        LinkedList<HashNode> llhn = harr[hash(k)];
        if ( llhn != null) {
            for (int i=0; i<llhn.size(); i++) {
                if (llhn.get(i).key == k)
                    llhn.remove(i);
            }
        }
    }

    // Print the entries in the hashtable
    public void print() {
        for (int i=0; i<harr.length; i++) {
            if ( harr[i] != null )
                for (int j=0; j<harr[i].size(); i++)
                    System.out.println(harr[i].get(j).key 
                        + " : " + harr[i].get(j).value);
        }
            
    }
}
