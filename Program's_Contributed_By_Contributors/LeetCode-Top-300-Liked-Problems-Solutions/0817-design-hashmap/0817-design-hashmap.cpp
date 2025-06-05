class MyHashMap {
public:
    vector<int> mp;

    MyHashMap() {
        // Initialize the vector with size 1000001 and fill it with -1
        mp = vector<int>(1000001, -1);
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};
