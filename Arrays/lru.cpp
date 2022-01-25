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
	void addKeyToSet(string key) {
		int countVal = count(this->keys.begin(), this->keys.end(), key);
		if (countVal > 0) this->keys.remove(key);
		this->keys.push_back(key);
	}
	
	// Time: O(N) | Space: O(N)
  void insertKeyValuePair(string key, int value) {
		int currentSize = this->keys.size();
		
		// if size of LRU cache is full
		if (currentSize == this->maxSize) {
			string expiredKey = this->keys.front();
			this->keysVsValueMap.erase(expiredKey);
			this->keys.remove(expiredKey);		
		}
		
		addKeyToSet(key);
    this->keysVsValueMap[key] = value;
  }

	// Time: O(N) | Space: O(1)
  int *getValueFromKey(string key) {
		if (this->keysVsValueMap.find(key) == this->keysVsValueMap.end()) return nullptr;
		addKeyToSet(key);
		return &this->keysVsValueMap[key];
  }

	// Time: O(1) | Space: O(N)
  string getMostRecentKey() {
		return this->keys.back();
  }
};
