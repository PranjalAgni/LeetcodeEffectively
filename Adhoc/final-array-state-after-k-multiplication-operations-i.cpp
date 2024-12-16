// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/ 

// Time: O(k* nlogn) | Space: O(n)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> vp;
        int N = nums.size();
        
        for (int idx = 0; idx < N; idx++) {
            vp.push_back(make_pair(nums[idx], idx));
        }
        
        sort(vp.begin(), vp.end());
        int pos = 0;
        while (k-- > 0) {
            pair<int, int> p = vp[0];
            int val = p.first * multiplier;            
            vp[0] = make_pair(val, p.second);
            sort(vp.begin(), vp.end());
        }
        
        for (pair<int, int>& p: vp) {
            nums[p.second] = p.first;
        }
        
        return nums;
        
    }
};