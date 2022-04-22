class MyHashMap {
public:
    // Time: O(1) | Space: O(int(1e6))
    /** Initialize your data structure here. */
    long long SIZE = 1e6 + 7;
    vector<int> hashMap;
    MyHashMap() {
        hashMap = vector<int>(SIZE, -1);
    }
    
    // Time: O(1) | Space: O(1)
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    // Time: O(1) | Space: O(1)
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashMap[key];
    }
    
    // Time: O(1) | Space: O(1)
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */