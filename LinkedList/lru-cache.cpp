class LRUCache {
   public:
    unordered_map<int, pair<int, list<int>::iterator>> hashMap;
    list<int> keys;
    int cacheCapacity;
    LRUCache(int capacity) {
        cacheCapacity = capacity;
        hashMap = unordered_map<int, pair<int, list<int>::iterator>>();
        keys = list<int>();
    }

    int get(int key) {
        int ans = -1;
        if (hashMap.find(key) != hashMap.end()) {
            ans = hashMap[key].first;
            keys.erase(hashMap[key].second);
            keys.push_front(key);
            hashMap[key].second = keys.begin();
        }

        return ans;
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            keys.erase(hashMap[key].second);
        }

        int currCapacity = keys.size();
        if (currCapacity == cacheCapacity) {
            int poppedKey = keys.back();
            keys.pop_back();
            auto it = hashMap.find(poppedKey);
            hashMap.erase(it);
        }

        keys.push_front(key);
        hashMap[key] = {value, keys.begin()};
    }
};
