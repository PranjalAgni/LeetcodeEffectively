class Solution {
public:
    // Time: O(N * N) | Space: O(N * N)
    int threeSumMulti(vector<int>& arr, int target) {
        int N = arr.size();
        int ans = 0;
        long long MOD = 1e9 + 7;
        unordered_map<int, int> hashMap;
        for (int idx = 0; idx < N; idx++) {
          ans = (ans + hashMap[target - arr[idx]]) % MOD;
          for (int jdx = 0; jdx < idx; jdx++) hashMap[arr[idx] + arr[jdx]] += 1;
        }
      
        return ans;
    }
};