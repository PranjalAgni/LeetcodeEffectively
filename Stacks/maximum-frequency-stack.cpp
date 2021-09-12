// Approach: Using 2 hashMaps

// 1. push(int x): map the element (x) with frequency HashMap and update the
// maxfreq variable ( i.e. holds the maximum frequency till now ). setMap
// maintains a stack which contains all the elements with same frequency.

// 2. pop(): First get the maxfreq element from setMap and then decrement the
// frequency of the popped element. After popping, if the stack becomes empty
// then decrement the maxfreq.

class FreqStack {
   public:
    map<int, int> freqMap;
    map<int, stack<int>> setMap;
    int maxFrequency;
    FreqStack() {
        freqMap = map<int, int>();
        setMap = map<int, stack<int>>();
        maxFrequency = 0;
    }

    // Time: O(logN) | Space: O(N)
    // N is number of elements to be pushed
    void push(int val) {
        int freq = freqMap[val] + 1;
        freqMap[val] = freq;
        maxFrequency = max(maxFrequency, freq);
        setMap[freq].push(val);
    }

    // Time: O(1) | Space: O(N)
    // N is number of elements to be pushed
    int pop() {
        int val = setMap[maxFrequency].top();
        setMap[maxFrequency].pop();
        freqMap[val] -= 1;
        if (setMap[maxFrequency].empty()) maxFrequency -= 1;
        return val;
    }
};