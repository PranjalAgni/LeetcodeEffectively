// https://leetcode.com/problems/peeking-iterator/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
  // Time: O(1) | Space: O(N)
  vector<int> numList;
  int N;
  int pos;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      numList = nums;
      N = nums.size();
      pos = 0;
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Time: O(1) | Space: O(1)
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
    return numList[pos];
	}
	
    // Time: O(1) | Space: O(1)
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	  int val = numList[pos];
    pos += 1;  
    return val;
	}
	
    // Time: O(1) | Space: O(1)
	bool hasNext() const {
	  return pos < N;
	}
};