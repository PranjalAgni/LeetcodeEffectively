#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int maxSize;
	list<string> keys;		
	unordered_map<string, int> keysVsValueMap;
    LRUCache(int maxSize) { 
		this->maxSize = maxSize > 1 ? maxSize : 1;
		this->keys = list<string>();
		this->keysVsValueMap = unordered_map<string, int>();
	}
	
	// Time: O(N) | Space: O(N)
	void addKeyAndUpdateRecency(string key) {
	    this->keys.resize(this->maxSize);
		int countVal = count(this->keys.begin(), this->keys.end(), key);
		if (countVal > 0) this->keys.remove(key);
		this->keys.push_front(key);
	}
	
    // Time: O(N) | Space: O(N)
    void insertKeyValuePair(string key, int value) {
        int currentSize = this->keys.size();

        // if size of LRU cache is full
        if (currentSize == this->maxSize) {
            string expiredKey = this->keys.back();
            this->keysVsValueMap.erase(expiredKey);
        }
        
        addKeyAndUpdateRecency(key);
        this->keysVsValueMap[key] = value;
    }

	// Time: O(N) | Space: O(1)
    int *getValueFromKey(string key) {
		if (this->keysVsValueMap.find(key) == this->keysVsValueMap.end()) return nullptr;
		addKeyAndUpdateRecency(key);
		return &this->keysVsValueMap[key];
    }

    // Time: O(1) | Space: O(N)
    string getMostRecentKey() {
	   return this->keys.front();
    }
};
