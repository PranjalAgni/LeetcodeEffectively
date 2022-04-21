// https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    // Time: O(1) | Space: O(int(1e6))
    vector<int> hashSet;
    MyHashSet() {
        hashSet = vector<int>(int(1e6) + 1, 0);
    }
    
    // Time: O(1) | Space: O(1)
    void add(int key) {
        if (hashSet[key]) return;
        hashSet[key] = 1;
    }
    
    // Time: O(1) | Space: O(1)
    void remove(int key) {
        if (hashSet[key] == 0) return;
        hashSet[key] = 0;
    }
    
    // Time: O(1) | Space: O(1)
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (hashSet[key]) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */