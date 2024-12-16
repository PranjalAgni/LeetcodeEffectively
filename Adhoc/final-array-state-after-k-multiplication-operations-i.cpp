// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/ 

class Solution {
private:
    void print(vector<pair<int, int>>& vp) {
        for (pair<int, int>& p: vp) {
            cout << p.first << " ";
        }
        
        cout << endl;
    }
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
            nums[p.second] = val;
            vp[0] = make_pair(val, 0);
            sort(vp.begin(), vp.end());
            print(vp);
        }
        
        return nums;
        
    }
};