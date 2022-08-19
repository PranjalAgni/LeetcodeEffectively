class Solution {
private:
    // Time: O(N) | Space: O(int(1e5))
    // N = number of elements in the array
    vector<int> getFreqList(vector<int>& arr) {
      vector<int> freqList(1e5 + 5, 0);
      for (int& elt: arr) {
        freqList[elt] += 1;
      }
      return freqList;
    }
public:
    // Time: O(int(1e5) * log(int(1e5))) | Space: O(int(1e5))
    int minSetSize(vector<int>& arr) {
        vector<int> freqList = getFreqList(arr);
        sort(freqList.begin(), freqList.end(), greater<int>());
        int N = arr.size();
        int mid = N / 2;
        int ans = 0;
        for (int& freq: freqList) {
          mid -= freq;
          ans += 1;
          if (mid <= 0) return ans;
        }
      
      return -1; 
    }
};
